all: asm_cr corewar_cr

asm_cr:
	make -C src_asm

corewar_cr:
	make -C src_corewar

clean:
	make -C src_asm clean
	make -C src_corewar clean

fclean: clean
	make -C src_asm fclean
	make -C src_corewar fclean

re: fclean all
