#Get a string reverse using stack


.data
  string: .asciiz "fuego"
  reverse: .space 128
  n: .word 5

.text
main:
  #load the address of the string
  la $t0, string

  #load the address of the space in $t3
  la $t3, reverse

  #load the current counter
  li $t1, 0
  #load the string's length
  lw $t2, n

 push_stack:
    #substract from stack pointer
    subu $sp, $sp, 1
    sb $t0, 0($sp)
    #go to the next character
    addu $t0, $t0, 1
    #increment counter
    addu $t1, $t1, 1
    blt $t1, $t2, push_stack

  #pop form the current character
  pop_stack:
    lb $t2, 0($sp)
    sb $t2, 0($t3)
    addu $t3, $t3, 1
    addu $sp, $sp, 1

    #decrement counter
    subu $t1, $t1, 1
    bgt $t1, 0, pop_stack

  print_reversed:
    li $v0, 4
    la $a0, reverse
    syscall

  exit:
    li $v0, 10
    syscall
