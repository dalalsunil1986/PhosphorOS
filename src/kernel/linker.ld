ENTRY(_start)

SECTIONS
{
    . = 2M;

    .stivalehdr : {
        KEEP(*(.stivalehdr))
    }

    .text : {
        KEEP(*(.text*))
    }

    .rodata : {
        *(.rodata*)
    }

    .data : {
        *(.data*)
    }

    .bss : {
        *(COMMON)
        *(.bss*)
    }
}
