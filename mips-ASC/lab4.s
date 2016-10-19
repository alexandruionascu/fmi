.data
  string1: .asciiz "Insert array's length \n"
  string2: .asciiz "Insert array's elements \n"
  string3: .asciiz "The array is: \n"
  string4: .asciiz "\nPress: 1 for Sum, 2 for Last Element, 3 for Elements Bigger than N, 4 for Exit: \n"
  n: .word 0
  array: .space 64
  input: .word 0
  sum: .word 0
.text
main:
  #print string 1
  li $v0, 4
  la $a0, string1
  syscall

  #read n from keyboard
  li $v0, 5
  syscall
  #store n
  sw $v0, n

  #print string2
  li $v0, 4
  la $a0, string2
  syscall

  #store the counter in $t0
  li $t0, 0
  #store the array address in $t1
  la $t1, array
  #store n in $t3
  lw $t3, n
  #stores the input from user's keyboard

  read_array:
    li $v0, 5
    syscall
    sw $v0, ($t1)
    #go to the next address location
    addi $t1, 4
    #increment counter
    addi $t0, 1
    blt $t0, $t3, read_array

  #print string3
  li $v0, 4
  la $a0, string3
  syscall

  #store counter in $t0 and array's address in $t1
  la $t1, array
  li $t0, 0
  print_array:
    #print current element
    li $v0, 1
    lw $a0, ($t1)
    syscall
    #go to the next address
    addi $t1, 4
    #increment counter
    addi $t0, 1
    blt $t0, $t3, print_array

  print_menu:
    li $v0, 4
    la $a0, string4
    syscall

  switch_input:
    li $v0, 5
    syscall
    sw $v0, input
    lw $t0, input
    li $t1, 1
    li $t2, 2
    li $t3, 3
    li $t4, 4
    beq $t0, $t1, print_sum
    beq $t0, $t2, print_last_element
    beq $t0, $t3, bigger_elements
    beq $t0, $t4, exit

  print_sum:
    #counter
    li $t0, 0
    #current address
    la $t1, array
    #number of elements
    lw $t2, n
    #sum
    li $t3, 0

    sum_loop:
      lw $t4, ($t1)
      add $t3, $t3, $t4
      addi $t1, 4
      addi $t0, 1
      blt $t0, $t2, sum_loop
    #print result
    sw $t3, sum
    li $v0, 1
    lw $a0, sum
    syscall
    b print_menu

  print_last_element:
    #store n-1
    lw $t0, n
    sub $t0, 1
    li $t1, 4
    mult $t0, $t1
    mflo $t0
    la $t1, array
    add $t1, $t1, $t0
    #print element
    li $v0, 1
    lw $a0, ($t1)
    syscall
    b print_menu

  bigger_elements:
    li $t0, 0
    la $t1, array
    lw $t2, n

    bigger_elements_loop:
      beq $t0, $t2, print_menu
      addi $t0, 1
      lw $a0, ($t1)
      addi $t1, 4
      ble $a0, $t2, bigger_elements_loop
      li $v0, 1
      syscall
      b bigger_elements_loop



exit:
  li $v0, 10
  syscall
