How to debug

in one window:
openocd -f stm32h723zgtx.cfg

in the second window:
cd project_root
gdb-multiarch -x mu/debug/gdbinit


Fun stuff:
layout spilt
focus asm
step through asm: stepi(si) or nexti(ni)

