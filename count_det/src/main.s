.text
.global count_det

count_det:
    push {r4-r9}
    ldr r1, [r0], #4
    ldr r2, [r0], #4
    ldr r3, [r0], #4
    ldr r4, [r0], #4
    ldr r5, [r0], #4
    ldr r6, [r0], #4
    mul r7, r1, r5
    mul r8, r2, r4
    sub r7, r7, r8
    mul r8, r3, r4
    mul r9, r1, r6
    sub r8, r8, r9
    mul r1, r2, r6
    mul r9, r3, r5
    sub r9, r1, r9
    ldr r1, [r0], #4
    ldr r2, [r0], #4
    ldr r3, [r0], #4
    mul r1, r1, r9
    mul r2, r2, r8
    mul r3, r3, r7
    add r1, r1, r2
    add r1, r1, r3
    mov r0, r1
    pop {r4-r9}
    bx lr
    
