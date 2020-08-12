# PWM  (Pulse Width Modulation)
It is a technique that modulates the width of a rectangular pulse wave in order to get a variation in the average value of the resulting wave.

### Period
A period of a pulse consists of an ON cycle (HIGH) and an OFF cycle (LOW). 

### Duty Cycle
The fraction for which the signal is ON over a period is known as duty cycle.

Duty Cycle (In %) = \frac{Ton}{Ton + Toff} x 100

The main application of PWM is to control the power delivered to the load.
The power is controlled by switching the voltage between the supply and load at an extremely high rate.

## LPC2148 has PWM peripheral through which we can generate multiple PWM signals on PWM pins. Also, LPC2148 supports two types of controlled PWM outputs as

1. Single Edged PWM Signal
In case of Single Edged PWM, the pulse will be always at the beginning or the ending of the period. 
 Based on the position of the edge, the single edged PWM is again divided in to
 1. Trailling Edge PWM :  the pulse is fixed at the beginning of the period while the position of the trailing edge is varied.
 2. Leading Edge PWM : the pulse is fixed at the end of the period and the position of the leading edge is varied.
2. Double Edged PWM Signal

## LPC2148 PWM
- The PWM in LPC2148 is based on standard 32-bit Timer Counter, i.e. PWMTC (PWM Timer Counter). This Timer Counter counts the cycles of peripheral clock (PCLK).
- Also, we can scale this timer clock counts using 32-bit PWM Prescale Register (PWMPR).
- LPC2148 has 7 PWM match registers (PWMMR0 – PWMMR06).
- One match register (PWMMR0) is used to control the Duty Cycle or period of the PWM output.
- Remaining 6 match registers are used to set PWM width for 6 different PWM signals in Single Edge Controlled PWM or 3 different PWM signals in Double Edge Controlled PWM.

## PWM Resiters

**PWM Timer Control Register (PWMTCR):**
PWM Timer Control Register is used to control the PWM Timer Counter. This Timer Counter is specific to the PWM block. Bit 0 in the PWMTCR register is used to enable or disable the counter in PWM block. When this bit is 1, the PWM TC and PWM Prescale Counter are enabled. When this bit is 0, both are disabled. Bit 1 is used to reset the PWM TC and PWM Prescale Counter. Bit 3 is used to enable or disable the PWM Mode.

**PWM Prescale Register (PWMPR):**
PWM Prescale Register is used to set the resolution of the PWM outputs. The PWM TC will increment for every PWMPR + 1 PCLK cycles.

**PWM Match Registers (PWMMR0 – PWMMR6):**
 Each PWM Match Register is associated with each PWM pin i.e. PWM 1 to PWM 6 are associated with PWMMR1 to PWMMR6 respectively. The values in the PWM Match Register are compared with the value in PWM TC.

**PWM Match Control Register (PWMMCR):**
The PWM Match Control Register is used to control the operations that can be done when the value in the PWM Match registers and PWM TC register are same. Three bits are associated with each Match Register i.e. Bit 0, Bit 1 and Bit 2 for PWMMR0, Bit 3, Bit 4 and Bit 5 for PWMMR1, etc. If we consider PWMMR0, the Bit 0 in PWMMCR is used to enable an interrupt, Bit 1 is used to reset the PWM TC and Bit 2 is used to stop the PWM TC and PWM PC.

**PWM Interrupt Register (PWMIR):**
PWM Interrupt Register is used to identify the interrupts based on PWM Match Registers. There are 7 bits in PWMIR corresponding to 7 PWM Match Register Interrupts. When an interrupt occurs, the corresponding bit in the PWMIR register is set to HIGH. If the bit is manually set to HIGH, the interrupt is reset.

**PWM Latch Enable Register (PWMLER):**
When PWM Match Registers are used to generate PWM signals, the PWM Latch Enable Register is used to control its update. When the value of the PWM Match Registers are updated when the PWM is active, the values will be stored in a shadow register. When an event occurs on the PWMMR0 register, the values will be transferred to the Match Registers from the shadow register only if the corresponding bit in the PWMLER is set to 1.

**PWM Control Register (PWMPCR):**
 PWM Control Register is used to enable or disable the PWM outputs and also select the mode of PWM i.e. either single edge or double edge. Bit 2 to Bit 6 in the PWMPCR register are used to set the PWM output as either single edge or double edge for PWM2 to PWM6. Bit 9 to Bit 14 are used to enable or disable the PWM1 to PWM6 outputs respectively.

## Steps to Configure PWM

- Configure the GPIO pins for PWM operation in respective PINSEL register.
- Configure TCR to enable the Counter for incrementing the TC, and Enable the PWM block.
- Set the required pre-scalar value in PR.
- Configure MCR to reset the TC whenever it matches MR0.
- Update the Cycle time in MR0.
- Load the Duty cycles for required PWMx channels in respective match registers MRx(x: 1-6).
- Enable the bits in LER register to load and latch the new match values.
- Enable the required pwm channels in PCR register.