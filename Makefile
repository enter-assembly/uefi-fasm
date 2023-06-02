PROG := hello_efi

BOOT_FILE := bootx64

IMG_DIR := disk
IMG_FILE := ${IMG_DIR}/sd.img
IMG_SIZE_MiB := 256
LOOP_DEVICE := /dev/loop0

MOUNT_DIR := ${IMG_DIR}/mnt
BOOT_DIR := ${MOUNT_DIR}/EFI/boot
BIOS := /usr/share/ovmf/OVMF.fd

SRC_DIR := source
BUILD_DIR := build
EFI_EXEC := ${BUILD_DIR}/${BOOT_FILE}.efi

all: compile cp run

compile: ${SRC_DIR}/${PROG}.asm ${BUILD_DIR}
	fasm $<
	mv $(patsubst %.asm,%.efi,$<) ${EFI_EXEC}

${BUILD_DIR}:
	mkdir -p $@

cp: ${EFI_EXEC} ${BOOT_DIR}
	sudo cp $< ${BOOT_DIR}
	sync

${BOOT_DIR}: ${IMG_FILE} ${MOUNT_DIR}
	sudo mkdir -p $@

run: ${BIOS} ${IMG_FILE}
	qemu-system-x86_64 -bios ${BIOS} -hda ${IMG_FILE} -boot c

clean:
	rm -rf ${BUILD_DIR}

${MOUNT_DIR}:
	@echo Associating ${LOOP_DEVICE} with '${IMG_FILE}' file
	@sudo losetup -P ${LOOP_DEVICE} ${IMG_FILE}
	@echo Mounting ${LOOP_DEVICE}p1 to ${MOUNT_DIR}
	@mkdir -p ${MOUNT_DIR} && sudo mount ${LOOP_DEVICE}p1 ${MOUNT_DIR}

unmount_file:
	@echo Unmounting ${MOUNT_DIR}
	@sudo umount ${MOUNT_DIR} && rm -r ${MOUNT_DIR}
	@echo Disassociating ${LOOP_DEVICE}
	@sudo losetup -d ${LOOP_DEVICE}

make_efi_image: ${IMG_FILE}
	@echo Image file ${IMG_FILE} is ready

${IMG_FILE}:
	@echo Creating ${IMG_FILE} file
	@mkdir -p ${IMG_DIR} && dd if=/dev/zero of=$@ bs=1MiB count=${IMG_SIZE_MiB}
	@echo Associating ${LOOP_DEVICE} with '${IMG_FILE}' file
	@sudo losetup -P ${LOOP_DEVICE} ${IMG_FILE}
	@echo Making GPT filesystem with EFI partition
	@printf 'g\nn\n\n\n\nt\n1\nw\n' | sudo fdisk /dev/loop0 1> /dev/null
	@echo Making FAT32 on ${LOOP_DEVICE}p1
	@sudo mkfs.vfat -F32 -I ${LOOP_DEVICE}p1
	@echo Disassociating ${LOOP_DEVICE}
	@sudo losetup -d ${LOOP_DEVICE}
