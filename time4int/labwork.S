 # labwork.S
  # Written 2015-2017 by F Lundevall
  # Skeleton file for IS1200/IS1500 lab 1.
  # The macros PUSH and POP are in the public domain.
  # Please add your own code at the end of the file.

  #
  # Please keep the two macros PUSH and POP unchanged
  #
.global delay
.global time2string
.global enable_interrupt

.macro	PUSH reg
	addi	$sp,$sp,-4
	sw	\reg,0($sp)
.endm

.macro	POP reg
	lw	\reg,0($sp)
	addi	$sp,$sp,4
.endm
  #
  # Please add your own code below this line
  #

delay:
	add $t0, $0, $a0 	#(int ms)
while:				
	slt $t2, $t0, $0 	#( ms > 0 )
	bne $t2, $0, dwhile	#  while the above is true
	nop
	addi $t0, $t0, -1	# ms = ms – 1;
        add $t1, $0, $0		# int i  = 0;
for:
	slti  $t2, $t1, 4711 	#( i < 4711;)
	beq  $t2, $0, dfor	# for the above
	nop			# /* Do nothing. */
	addi $t1, $t1, 1	#i = i + 1 
	j for
	nop
dfor:
	j while			# close for
	nop
dwhile:				#close while
	jr $ra
	nop
  # you can write your code for subroutine "hexasc" below this line
hexasc:
and $a0, $a0, 0xF
slti $t1, $a0, 11
beq $t1, $0, letter
nop
#number
addi $v0, $a0, 48
jr $ra
nop

letter:
addi $v0, $a0, 55
jr $ra
nop
	
time2string: 	# Register $a0 contains the address of an area in memory 
		#The 16 least significant bits of register $a1 (in arg) contains time-info
	
	move $t8, $ra
	
	move $a3, $a0
	
	andi $a0,$a1,61440	#isolate minute bits (0x0000 5000)
	srl $a0,$a0,12		#shift minute bits (0x0000 0005)
	jal hexasc
	nop
	sb $v0, 0($a3) 		#store minute byte in a0 
	nop
	
	
	andi $a0,$a1,3840	#isolate minute bits (0x0000 0900)
	srl $a0,$a0,8		#shift minute bits (0x0000 0009)
	jal hexasc
	nop
	sb $v0, 1($a3) 		#store minute byte in a0 
	nop
	
	li $a0, 0x3A
	jal hexasc
	nop
	sb $v0, 2($a3) 		#store : byte in a0 
	nop

	andi $a0,$a1,240	#isolate second bits (0x0000 0050)
	srl $a0,$a0,4		#shift second bits (0x0000 0005)
	jal hexasc
	nop
	sb $v0, 3($a3) 		#store second byte in a0 
	nop
	
	andi $a0,$a1,15		#isolate second bits (0x0000 0008)
	jal hexasc
	nop
	sb $v0, 4($a3) 		#store second byte in a0 
	nop
	
	li $v0, 0x00
	sb $v0, 5($a3) 		#store null byte in a0 
	nop
	
	# HOUR ?
	
	andi $a0,$a1,15		#isolate second bits (0x0000 0008)
	addi $t9, $0, 0
	bne $a0,$t9, continue2string
	nop
	
	andi $a0,$a1,240	#isolate second bits (0x0000 0050)
	bne $a0,$t9, continue2string
	nop
	
	andi $a0,$a1,3840	#isolate minute bits (0x0000 0900)
	bne $a0,$t9, continue2string
	nop
	
	andi $a0,$a1,61440	#isolate minute bits (0x0000 5000)
	bne $a0,$t9, continue2string
	nop
	
	li $t1,0x48
	sb $t1, 0($a3) 		#store N byte in a0 
	
        li $t2,0x4f
	sb $t2, 1($a3) 		#store I
	
	li $t3,0x55
	sb $t3, 2($a3) 		#store N byte in a0 
	
	li $t4,0x52
	sb $t4, 3($a3) 		#store E

        li $t5,0x20
        sb $t5, 4($a3)
        
	continue2string:

	move $ra, $t8
	move $a0, $a3
	jr $ra
	nop

enable_interrupt:
ei
jr $ra
nop