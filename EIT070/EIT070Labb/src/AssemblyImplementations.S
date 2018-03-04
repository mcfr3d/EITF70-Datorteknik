.global readSwitches_writeLed_Assembly
.text
.ent readSwitches_writeLed_Assembly
readSwitches_writeLed_Assembly:
lwi r11,r0, 0x40020000
swi r11,r0, 0x40010000
rtsd r15,8
nop
.end readSwitches_writeLed_Assembly

// function
.global function
.text
.ent function
function:
addi r1,r1,-4
swi r15,r1,0
lwi r5,r0, 0x40020000
brlid r15, number_of_ones
nop
add r5,r3,r0
brlid r15,translateN
nop
swi r3,r0,0x40010000
lwi r15,r1,0
addi r1,r1,4
rtsd r15, 8
nop
.end function

//number_of_oens
.global number_of_ones
.text
.ent number_of_ones
number_of_ones:
add r3,r0,r0
while: beqid r5, result
nop
andi r4,r5,1
add r3,r3,r4
sra r5,r5
brid while
nop
result: rtsd r15, 8
nop
.end number_of_ones

//translateN
.global translateN
.text
.ent translateN
translateN:
addi r3,r0,1
again: beqid r5, done
nop
addi r5,r5,-1
add r3,r3,r3
brid again
nop
done: addi r3,r3,-1
rtsd r15, 8
nop
.end translateN

//process_switches
.global process_switches
.text
.ent process_switches
process_switches:
addi r1,r1,-4
sw r15,r1,r0
lwi r6,r0, 0x40020000
add r5,r0,r0
addi r7,r0,8
addi r10,r0,1
shift: beqi r7, arg_ready
nop
andi r9, r6,1
add r5,r5,r5
add r5,r5,r9
sra r6,r6
rsub r7,r10,r7
brid shift
nop
arg_ready: brlid r15, number_of_ones
nop
add r7,r3,r0
add r5,r6,r0
brlid r15, first_position_of_one
nop
add r6,r3,r0
add r5,r7,r0
brlid r15, display_value_at_index
nop
lw r15,r1,r0
addi r1,r1,4
rtsd r15, 8
nop
.end process_switches

//first_position_of_one
.global first_position_of_one
.text
.ent first_position_of_one
first_position_of_one:
add r3,r0,r0
beqi r5, found
nop
next: andi r4,r5,1
bneid r4, found
nop
addi r3,r3,1
sra r5,r5
brid next
nop
found: rtsd r15,8
nop
.end first_position_of_one

//display_value_at_index
.global display_value_at_index
.text
.ent display_value_at_index
display_value_at_index:
add r7,r5,r5
add r7,r7,r7
add r8,r6,r6
add r8,r8,r8
addi r9,r0,7
addi r10,r0,0x44A00000
addi r11,r0,1
reset_display: add r12, r9,r9
add r12,r12,r12
sw r0,r10,r12
rsub r9,r11,r9
bgeid r9, reset_display
nop
lwi r9,r7,display_codes
sw r9, r10, r8
rtsd r15, 8
nop
.end display_value_at_index
/*
// Labb 3 assignment 7
//compare_left_right
.global compare_left_right
.text
.ent compare_left_right
compare_left_right:
lwi r5, r0, 0x40020000 //switches_data in r5
andi r6, r5, 0b0000000011111111 //RIGHT in r6
add r7, r5, r0 //switches_data in r7
addi r8, r0, 8
addi r9, r0, 1
shifta: beqi r8, continue
nop
sra r7, r7
rsub r8, r9, r8
brid shifta
nop
continue: rsub r10, r6, r7
bgti r10 , leds_on
nop
swi r0, r0, 0x40010000
bri end_if
nop
leds_on: addi r11, r0, -1
swi r11, r0, 0x40010000
end_if: rtsd r15, 8
nop
.end compare_left_right
*/
//assignment 8
.global compare_pairs
.text
.ent compare_pairs
compare_pairs:
lwi r5, r0, 0x40020000 //switches_data in r5
andi r6, r5, 0b0000000011111111 //RIGHT in r6
add r7, r5, r0 //switches_data in r7
addi r8, r0, 8
addi r9, r0, 1
shifta: beqi r8, continue
nop
sra r7, r7
rsub r8, r9, r8
brid shifta
nop //LEFT in r7
continue: xor r10, r6, r7
addi r11, r0, -1
andn r10, r11, r10

addi r8, r0, 7
addi r9, r0, 1
shifta2:andi r3,r10,1
rsubik r12,r8,7
add r4,r3,r3 // digit in r4
add r4,r4,r4
add r6,r12,r12 // index in r6
add r6,r6,r6
addi r7,r0,0x44A00000 //display base in r7
lwi r11,r4,display_codes
sw r11, r7, r6

rsub r8, r9, r8
sra r10,r10
bgeid r8, shifta2
nop
continue2: rtsd r15, 8
nop
.end compare_pairs



.global testLed
.text
.ent testLed
testLed:
add r7,r5,r5 // digit in r7
add r7,r7,r7
add r8,r6,r6 // index in r8
add r8,r8,r8
addi r10,r0,0x44A00000 //display base
lwi r9,r7,display_codes
sw r9, r10, r8
rtsd r15, 8
nop
.end testLed

.global process_all_switches
.text
.ent process_all_switches
process_all_switches:
addi r1,r1,-4
sw r15,r1,r0
addi r9,r0,7
addi r10,r0,0x44A00000
addi r11,r0,1
reset_display2: add r12, r9,r9
add r12,r12,r12
sw r0,r10,r12
rsub r9,r11,r9
bgeid r9, reset_display2
nop

lwi r5,r0,0x40020000
brlid r15,number_of_ones
nop
//now we have number of ones in r3
rsubik r4,r3,9
blti r4, true1// if statement
//False block below here
add r4,r3,r3 // digit in r4
add r4,r4,r4
addi r6,r0,1 // index in r6
add r6,r6,r6
addi r7,r0,0x44A00000 //display base in r7
lwi r11,r4,display_codes
sw r11, r7, r6
bri end_if2 //end of false block
true1:   //True block here

addi r4,r0,2   // digit 1 in r4 (has index 2)
add r4,r4,r4
addi r6,r0,2   //index of display
add r6,r6,r6
addi r7,r0,0x44A00000 //display base in r7
lwi r11,r4,display_codes
sw r11, r7, r6

//sub 10 from r3
addi r8,r0,10
rsub r8,r8,r3

add r4,r8,r8 // digit in r4
add r4,r4,r4
addi r6,r0,1 // index in r6
add r6,r6,r6
addi r7,r0,0x44A00000 //display base in r7
lwi r11,r4,display_codes
sw r11, r7, r6
bri end_if2

end_if2:lw r15,r1,r0 //contin progra
addi r1,r1,4
rtsd r15, 8
nop
.end process_all_switches


