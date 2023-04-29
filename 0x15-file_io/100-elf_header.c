#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <elf.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <stdlib.h>

void ver_printer(unsigned char *e_ident);
void abi_printer(unsigned char *e_ident);
void os_abi_printer(unsigned char *e_ident);
void dt_printer(unsigned char *e_ident);
void type_printer(unsigned int e_type, unsigned char *e_ident);
void elf_checker(unsigned char *e_ident);
void magic_printer(unsigned char *e_ident);
void cls_printer(unsigned char *e_ident);
void entry_printer(unsigned long int e_entry, unsigned char *e_ident);
void elf_close(int elf);

/**
 * elf_checker - elf checker
 * @e_ident: pointer to array containing the ELF magic numbers.
 **/
void elf_checker(unsigned char *e_ident)
{
	int index;

	for (index = 0; index < 4; index++)
	{
		if (e_ident[index] != 127 &&
				e_ident[index] != 'E' &&
				e_ident[index] != 'L' &&
				e_ident[index] != 'F')
		{
			dprintf(STDERR_FILENO, "Error: Not an ELF file\n");
			exit(98);
		}
	}
}

/**
 * magic_printer - prints magic numbers of an ELF header.
 * @e_ident: Pointer to an array containing the ELF magic numbers.
 **/
void magic_printer(unsigned char *e_ident)
{
	int index;

	printf("  Magic:   ");

	for (index = 0; index < EI_NIDENT; index++)
	{
		printf("%02x", e_ident[index]);

		if (index == EI_NIDENT - 1)
			printf("\n");
		else
			printf(" ");
	}
}

/**
 * cls_printer - Prints the class of an ELF header.
 * @e_ident: Pointer to an array containing the ELF class.
 **/
void cls_printer(unsigned char *e_ident)
{
	printf("  Class:                             ");

	switch (e_ident[EI_CLASS])
	{
		case ELFCLASSNONE:
			printf("none\n");
			break;
		case ELFCLASS32:
			printf("ELF32\n");
			break;
		case ELFCLASS64:
			printf("ELF64\n");
			break;
		default:
			printf("<unknown: %x>\n", e_ident[EI_CLASS]);
	}
}

/**
 * dt_printer - Prints the data of an ELF header.
 * @e_ident: Pointer to an array containing the ELF class.
 **/
void dt_printer(unsigned char *e_ident)
{
	printf("  Data:                              ");

	switch (e_ident[EI_DATA])
	{
		case ELFDATANONE:
			printf("none\n");
			break;
		case ELFDATA2LSB:
			printf("2's complement, little endian\n");
			break;
		case ELFDATA2MSB:
			printf("2's complement, big endian\n");
			break;
		default:
			printf("<unknown: %x>\n", e_ident[EI_CLASS]);
	}
}

/**
 * ver_printer - Prints the version of an ELF header.
 * @e_ident: Pointer to an array containing the ELF version.
 **/
void ver_printer(unsigned char *e_ident)
{
	printf("  Version:                           %d",
			e_ident[EI_VERSION]);

	switch (e_ident[EI_VERSION])
	{
		case EV_CURRENT:
			printf(" (current)\n");
			break;
		default:
			printf("\n");
			break;
	}
}

/**
 * os_abi_printer - Prints the OS/ABI of an ELF header.
 * @e_ident: Pointer to an array containing the ELF version.
 **/
void os_abi_printer(unsigned char *e_ident)
{
	printf("  OS/ABI:                            ");

	switch (e_ident[EI_OSABI])
	{
		case ELFOSABI_NONE:
			printf("UNIX - System V\n");
			break;
		case ELFOSABI_HPUX:
			printf("UNIX - HP-UX\n");
			break;
		case ELFOSABI_NETBSD:
			printf("UNIX - NetBSD\n");
			break;
		case ELFOSABI_LINUX:
			printf("UNIX - Linux\n");
			break;
		case ELFOSABI_SOLARIS:
			printf("UNIX - Solaris\n");
			break;
		case ELFOSABI_IRIX:
			printf("UNIX - IRIX\n");
			break;
		case ELFOSABI_FREEBSD:
			printf("UNIX - FreeBSD\n");
			break;
		case ELFOSABI_TRU64:
			printf("UNIX - TRU64\n");
			break;
		case ELFOSABI_ARM:
			printf("ARM\n");
			break;
		case ELFOSABI_STANDALONE:
			printf("Standalone App\n");
			break;
		default:
			printf("<unknown: %x>\n", e_ident[EI_OSABI]);
	}
}

/**
 * abi_printer - prints the ABI version of an ELF header
 * @e_ident: Pointer to an array containing the ELF ABI version.
 **/
void abi_printer(unsigned char *e_ident)
{
	printf("  ABI Version:                       %d\n",
			e_ident[EI_ABIVERSION]);
}

/**
 * type_printer - Prints the type of an ELF header.
 * @e_type: ELF type
 * @e_ident: Pointer to an array containing the ELF class
 **/
void type_printer(unsigned int e_type, unsigned char *e_ident)
{
	if (e_ident[EI_DATA] == ELFDATA2MSB)
		e_type >>= 8;

	printf("  Type:                              ");

	switch (e_type)
	{
		case ET_NONE:
			printf("NONE (None)\n");
			break;
		case ET_REL:
			printf("REL (Relocatable file)\n");
			break;
		case ET_EXEC:
			printf("EXEC (Executable file)\n");
			break;
		case ET_DYN:
			printf("DYN (Shared object file)\n");
			break;
		case ET_CORE:
			printf("CORE (Core file)\n");
			break;
		default:
			printf("<unknown: %x>\n", e_type);
	}
}

/**
 * entry_printer - Prints the entry point of an ELF header
 * @e_entry: address of the ELF entry point
 * @e_ident: Pointer to an array containing the ELF class
 **/
void entry_printer(unsigned long int e_entry, unsigned char *e_ident)
{
	printf("  Entry point address:               ");

	if (e_ident[EI_DATA] == ELFDATA2MSB)
	{
		e_entry = ((e_entry << 8) & 0xFF00FF00) |
			((e_entry >> 8) & 0xFF00FF);
		e_entry = (e_entry << 16) | (e_entry >> 16);
	}

	if (e_ident[EI_CLASS] == ELFCLASS32)
		printf("%#x\n", (unsigned int)e_entry);

	else
		printf("%#lx\n", e_entry);
}

/**
 * elf_close - close an ELF file.
 * @elf: file descriptor of the ELF file.
 **/
void elf_close(int elf)
{
	if (close(elf) == -1)
	{
		dprintf(STDERR_FILENO,
				"Error: Can't close fd %d\n", elf);
		exit(98);
	}
}

/**
 * main - displays elf header info.
 * @argc: function argument count
 * @argv: function argument vector
 *
 * Return: 0 on success.
 **/
int main(int __attribute__((__unused__)) argc, char *argv[])
{
	Elf64_Ehdr *header;
	int o, r;

	o = open(argv[1], O_RDONLY);
	if (o == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argv[1]);
		exit(98);
	}
	header = malloc(sizeof(Elf64_Ehdr));
	if (header == NULL)
	{
		elf_close(o);
		dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argv[1]);
		exit(98);
	}
	r = read(o, header, sizeof(Elf64_Ehdr));
	if (r == -1)
	{
		free(header);
		elf_close(o);
		dprintf(STDERR_FILENO, "Error: `%s`: No such file\n", argv[1]);
		exit(98);
	}
	elf_checker(header->e_ident);
	printf("ELF Header:\n");
	magic_printer(header->e_ident);
	cls_printer(header->e_ident);
	dt_printer(header->e_ident);
	ver_printer(header->e_ident);
	os_abi_printer(header->e_ident);
	abi_printer(header->e_ident);
	type_printer(header->e_type, header->e_ident);
	entry_printer(header->e_entry, header->e_ident);
	free(header);
	elf_close(o);
	return (0);
}
