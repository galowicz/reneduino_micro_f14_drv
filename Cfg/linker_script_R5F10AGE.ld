MEMORY
{
	VEC : ORIGIN = 0x0, LENGTH = 4
	IVEC : ORIGIN = 0x4, LENGTH = 188
	CALLT0 : ORIGIN = 0x80, LENGTH = 0x40
	OPT : ORIGIN = 0xC0, LENGTH = 4
	SEC_ID : ORIGIN = 0xC4, LENGTH = 10
	OCDSTAD : ORIGIN = 0xCE, LENGTH = 10
	OCDROM : ORIGIN = 0xFE00, LENGTH = 512
	ROM : ORIGIN = 0xD8, LENGTH = 64808
	MIRROR : ORIGIN = 0xF2000, LENGTH = 52992
	SADDR : ORIGIN = 0xffe20, LENGTH = 0x000a0
	RAM : ORIGIN = 0xFEF00, LENGTH = 4096
	SELFRAM : ORIGIN = 0xFEF00, LENGTH = 1024
	TRACERAM  : ORIGIN = 0xFF300, LENGTH = 128
	HOTPLUGINRAM  : ORIGIN = 0xFF400, LENGTH = 48
}

EXTERN(vec vects callt0 option_bytes security_id init fini preinit_array init_array fini_array eh_frame_hdr eh_frame)

SECTIONS
{
	.vec 0x0: AT(0x0)
	{
		KEEP(*(.vec))
	} > VEC
	.vects 0x4: AT(0x4)
	{
		KEEP(*(.vects))
	} > IVEC

	.callt0 0x80 : AT(0x80)
	{
		. = ALIGN(2);
		KEEP(*(.callt0))
	} >CALLT0

	.option_byte 0xC0 : AT(0xC0)
	{
		KEEP(*(.option_bytes))
	} > OPT
	.security_id 0xC4: AT(0xC4)
	{
		KEEP(*(.security_id))
	} > SEC_ID
	.lowtext 0xD8: AT(0xD8)
	{
		*(.plt)
		*(.lowtext)
	} > ROM

	__mdata = .;

	.text (. + __romdatacopysize): 
	{
		*(.text)
		*(.text.*)
		/*INPUT_SECTION_FLAGS(SHF_EXECINSTR) *(*_n)*/
	} >ROM AT>ROM

	.init :
	{
		KEEP(*(.init))
	} >ROM

	.fini :
	{
		KEEP(*(.fini))
	} >ROM

	PROVIDE(__rodata_limit = CONSTANT(MIRRORAREASTART)+0x2000 + LENGTH(MIRROR));

	/* The rodata section is placed in MIRROR area in order to access as near addressing. */
	.rodata MAX(., (CONSTANT(MIRRORAREASTART)+0x2000)):
	{
		. = ALIGN(2);
		__rodata = .;
		*(.rodata)
		*(.rodata.*)
		. = ALIGN(2);
		*(.const)
		*(.const.*)

		. = ALIGN(2);
		PROVIDE(__init_array_start = .);
		KEEP(*(SORT(.init_array.*)))
		KEEP(*(.init_array))
		PROVIDE(__init_array_end = .);
		PROVIDE(__fini_array_start = .);
		KEEP(*(.fini_array))
		KEEP(*(SORT(.fini_array.*)))
		PROVIDE(__fini_array_end = .);	
		__erodata = .;
		/*The rodata section is copied into the MIRROR area, that is why we check if the start and end addresses for rodata are less then  _rodata_limit*/
		ASSERT((SIZEOF (.rodata) == 0) || (__rodata < __rodata_limit), "Error: rodata section start address is too large. Move the text section after the rodata section to ensure that correct data is added to the MIRROR area.");
		ASSERT((SIZEOF (.rodata) == 0) || (__erodata <= __rodata_limit), "Error: rodata section size exceeds length of the MIRROR area.");

	}>ROM


	.textf :
	{
		*(.textf)
		*(.textf.*)
		/*INPUT_SECTION_FLAGS(SHF_EXECINSTR) *(*_f)*/
	}>ROM

	.frodata :
	{
		. = ALIGN(2);
		__frodata = .;
		*(.frodata)
		*(.frodata.*)
		__efrodata = .;

		. = ALIGN(2);
		__constf = .;
		*(.constf)
		*(.constf.*)
		__econstf = .;
	} >ROM

	.eh_frame_hdr :
	{
		KEEP(*(.eh_frame_hdr))
	} > ROM
	.eh_frame :
	{
		KEEP(*(.eh_frame))
	} > ROM

	.data 0xFEF00 : AT(__mdata)
	{
		. = ALIGN(2);
		PROVIDE (__datastart = .);
		__data = .;
		*(.data)
		*(.data.*)
		. = ALIGN(2);
		/*INPUT_SECTION_FLAGS(!SHF_EXECINSTR, SHF_WRITE, SHF_ALLOC) *(*_n)*/
		__edata = .;
	} >RAM


	PROVIDE(__romdatastart = LOADADDR(.data));
	PROVIDE (__romdatacopysize = SIZEOF(.data));


	.dataf : {
		. = ALIGN(2);
		PROVIDE (__datafstart = .);
		. = ALIGN(2);
		*(.dataf)
		*(.dataf.*)
		/*INPUT_SECTION_FLAGS(!SHF_EXECINSTR, SHF_WRITE, SHF_ALLOC) *(*_f)*/
		. = ALIGN(2);
		PROVIDE (__datafend = .);
	} > RAM AT> ROM
	PROVIDE(__romdatafstart = LOADADDR(.dataf));
	PROVIDE (__romdatafcopysize = SIZEOF(.dataf));


	.sdata : {
		. = ALIGN(2);
		PROVIDE (__sdatastart = .);
		*(.sdata)
		*(.sdata.*)
		. = ALIGN(2);
		PROVIDE (__sdataend = .);
	} > SADDR AT> ROM

	 /* Note that crt0 assumes this is a multiple of two; all the
	 start/stop symbols are also assumed word-aligned.  */
	 PROVIDE(__romsdatastart = LOADADDR(.sdata));
	 PROVIDE (__romsdatacopysize = SIZEOF(.sdata));


	.saddr : {

		. = ALIGN(2);
		PROVIDE (__saddrstart = .);
		*(.saddr)
		. = ALIGN(2);

	} >SADDR AT>ROM
	PROVIDE(__romsaddrstart = LOADADDR(.saddr));
	PROVIDE (__romsaddrcopysize = SIZEOF(.saddr));



	.sbss :
	{
		PROVIDE(__sbssstart = .);
		. = ALIGN(2);
		__sbss = .;
		*(.sbss)
		*(.sbss.*)
		/*INPUT_SECTION_FLAGS(!SHF_EXECINSTR, SHF_WRITE, SHF_ALLOC) *(*_s)*/
		. = ALIGN(2);
		*(.sbss_bit)
		. = ALIGN(2);
		__esbss = .;

	} >SADDR AT>SADDR
	PROVIDE(__sbsssize = SIZEOF(.sbss));

	.bss :
	{
		PROVIDE(__bssstart = .);
		. = ALIGN(2);
		__bss = .;
		*(.bss)
		*(.bss.*)
		. = ALIGN(2);
		*(.bss_bit)
		. = ALIGN(2);
		*(COMMON)
		. = ALIGN(2);
		__ebss = .;
	} >RAM AT>RAM
	PROVIDE(__bsssize = SIZEOF(.bss));

	
	.bssf (NOLOAD):
	{
		PROVIDE(__bssfstart = .);
		. = ALIGN(2);
		*(.bssf)
		*(.bssf.*)
		/*INPUT_SECTION_FLAGS(!SHF_EXECINSTR, SHF_WRITE, SHF_ALLOC) *(*_f)*/
		. = ALIGN(128);
		__end = .;
	} >RAM AT>RAM
	PROVIDE(__bssfsize = SIZEOF(.bssf));

	PROVIDE(__stack_size = 0x100);
	.stack 0xFFE20 (NOLOAD) : AT(0xFFE20)
	{

		PROVIDE(__stack = .);
		ASSERT((__stack > (__end + __stack_size)), "Error: Too much data - no room left for the stack");
	} >RAM

	/DISCARD/ :
	{
		*(.note)
		*(.note.*)
		*(.gnu.warning*)
	}
}
