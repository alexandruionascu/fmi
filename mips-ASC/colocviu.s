.data
  string: .space 128
  text1: .asciiz "Please insert N \n"
  text2: .asciiz "Please insert the string \n"
  n: .word 0
  yes: .asciiz "Yes \n"
  no: .asciiz "No \n"
  matches: .word 0
.text

main:
  #print text1
  li $v0, 4
  la $a0, text1
  syscall

  #read n from keyboard
  li $v0, 5
  syscall
  #store n
  sw $v0, n

  #print text1
  li $v0, 4
  la $a0, text2
  syscall

  #read string
  li $v0, 8
  la $a0, string
  move $a1, $a2
  syscall

  #print string
  li $v0,4
  la $a0, string
  syscall

  #set arugments
  la $a0, string
  li $a1, 'c'

  #call the subroutine
  jal checkCharacter
  b exit

checkCharacter:
  #matches counter
  li $t3, 0
  #store the length
  lw $t4, n

  incrementCounter:
    addu $t3, $t3, 1
    
  check:
    lb $t5, ($a0)
    beq $t5, $a1, incrementCounter
    addu $a0, $a0, 1
    bne $a0, $a1, check

  bgt $t3, 2, printYes
  blt $t3, 2, printNo

  sw $t3, matches
  li $v0, 1
  lw $a0, matches
  syscall
  #return the number of matches
  move $v0, $t3
  jr $ra




printYes:
  #print no
  li $v0,4
  la $a0, yes
  syscall


printNo:
  #print no
  li $v0,4
  la $a0, no
  syscall

exit:
  li $v0, 10
  syscall
