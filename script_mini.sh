#!/bin/bash

echo ""
echo "batman.s"
./asm champions/batman.s
hexdump -vC champions/batman.cor > my_file
./resources/vm_champs/asm champions_disassemble/batman.s
./asm champions_disassemble/batman.cor
./resources/vm_champs/asm champions_disassemble/batman.s
hexdump -vC champions_disassemble/batman.cor > original_after_disassemble
./resources/vm_champs/asm champions/batman.s
hexdump -vC champions/batman.cor > original
if (diff my_file original && diff my_file original_after_disassemble && diff original original_after_disassemble)
then
    echo "[OK] - diff"
else
    echo "[KO] - diff"
fi
rm -rf my_file original original_after_disassemble champions/*.cor champions_disassemble/*
cp champions/* champions_disassemble/