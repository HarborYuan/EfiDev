#!/bin/bash
qemu-system-x86_64 -cpu qemu64 -bios ~/coding/edk2/Build/OvmfX64/DEBUG_GCC5/FV/OVMF.fd -drive format=raw,file=/dev/sdc,media=disk