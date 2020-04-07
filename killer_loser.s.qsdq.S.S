;123123




.name "Code 











Killer"
.comment "Hi everyone. 







I'm comming"

start:	st r1, 39
		st r1, 39

prep:	ld %9, r3
		ld %1, r2
		ld %-5, r4
		ld %0, r5

live1:	live %0
live2:	live %0

		fork %:next
		zjmp %:live1

next:	st r1, 6
rewr:	live %0
		st r2, 27
		st r1, 22 #5
		st r3, 22
		st r4, 17

fork1:	fork %:loop #3
		zjmp %:rewr #3

loop:	live %17
		zjmp %22
