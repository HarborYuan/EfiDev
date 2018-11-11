#include <efi.h>
#include <efilib.h>


static const CHAR16 KernelFilePath[] = L"Tomato/System/OSKernel.exe";

EFI_STATUS
EFIAPI 
efi_main(EFI_HANDLE ImageHandle, EFI_SYSTEM_TABLE *SystemTable) 
{
    EFI_STATUS status;
	InitializeLib(ImageHandle, SystemTable);
    EFI_BOOT_SERVICES *bs = ST->BootServices;
    EFI_RUNTIME_SERVICES *rs = ST->RuntimeServices;

    EFI_LOADED_IMAGE* loadedImage;
    EFI_FILE_IO_INTERFACE* volume;

    bs->HandleProtocol(ImageHandle, &LoadedImageProtocol, (void**)&loadedImage);
    bs->HandleProtocol(loadedImage->DeviceHandle, &FileSystemProtocol, (void**)&volume);
    EFI_FILE_HANDLE rootFS, fileHandle;
    status = volume->OpenVolume(volume, &rootFS);
    status = rootFS->Open(rootFS, &fileHandle, (CHAR16*)KernelFilePath, EFI_FILE_MODE_READ, 0);
    Print (L"%s",rootFS);
    return status;
    /*
    UINT8* kernelBuffer;
    bs->AllocatePool(EfiLoaderData, 1000, (void**)&kernelBuffer);
    fileHandle->Read(fileHandle, &KernelPoolSize, kernelBuffer);
    fileHandle->Close(fileHandle);
    return status;
    */
}