EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 3 7
Title "Bit Crusher Pedal"
Date "2020-07-27"
Rev "0"
Comp ""
Comment1 "creativecommons.org/licenses/by/4.0/"
Comment2 "License: CC by 4.0"
Comment3 "Author: Jordan Aceto"
Comment4 ""
$EndDescr
$Comp
L Device:R R?
U 1 1 5F1F7EDD
P 5250 3550
AR Path="/5F1223E3/5F1F7EDD" Ref="R?"  Part="1" 
AR Path="/5F122414/5F1F7EDD" Ref="R6"  Part="1" 
F 0 "R6" V 5150 3500 50  0000 L CNN
F 1 "390k" V 5250 3450 50  0000 L CNN
F 2 "Resistor_SMD:R_0805_2012Metric_Pad1.15x1.40mm_HandSolder" V 5180 3550 50  0001 C CNN
F 3 "~" H 5250 3550 50  0001 C CNN
	1    5250 3550
	0    1    1    0   
$EndComp
Wire Wire Line
	5700 3300 5500 3300
Wire Wire Line
	5500 3300 5500 3550
Wire Wire Line
	5500 3550 5600 3550
Wire Wire Line
	6200 3650 6250 3650
Wire Wire Line
	6250 3650 6250 3300
Wire Wire Line
	6250 3300 6100 3300
Connection ~ 5500 3550
$Comp
L Amplifier_Operational:MCP6002-xP U?
U 1 1 5F1F7F02
P 5900 3650
AR Path="/5F1223E3/5F1F7F02" Ref="U?"  Part="1" 
AR Path="/5F122414/5F1F7F02" Ref="U1"  Part="1" 
F 0 "U1" H 6100 3800 50  0000 C CNN
F 1 "MCP6002-xP" H 6150 3900 50  0000 C CNN
F 2 "Package_SO:SOIC-8_3.9x4.9mm_P1.27mm" H 5900 3650 50  0001 C CNN
F 3 "http://ww1.microchip.com/downloads/en/DeviceDoc/21733j.pdf" H 5900 3650 50  0001 C CNN
	1    5900 3650
	1    0    0    1   
$EndComp
Wire Wire Line
	5400 3550 5500 3550
$Comp
L Device:R R?
U 1 1 5F1F9AD5
P 5750 4200
AR Path="/5F1223E3/5F1F9AD5" Ref="R?"  Part="1" 
AR Path="/5F122414/5F1F9AD5" Ref="R8"  Part="1" 
F 0 "R8" V 5650 4150 50  0000 L CNN
F 1 "1k8" V 5750 4100 50  0000 L CNN
F 2 "Resistor_SMD:R_0805_2012Metric_Pad1.15x1.40mm_HandSolder" V 5680 4200 50  0001 C CNN
F 3 "~" H 5750 4200 50  0001 C CNN
	1    5750 4200
	0    1    1    0   
$EndComp
$Comp
L Device:R R?
U 1 1 5F1FA0AF
P 5250 4200
AR Path="/5F1223E3/5F1FA0AF" Ref="R?"  Part="1" 
AR Path="/5F122414/5F1FA0AF" Ref="R7"  Part="1" 
F 0 "R7" V 5150 4150 50  0000 L CNN
F 1 "1k8" V 5250 4100 50  0000 L CNN
F 2 "Resistor_SMD:R_0805_2012Metric_Pad1.15x1.40mm_HandSolder" V 5180 4200 50  0001 C CNN
F 3 "~" H 5250 4200 50  0001 C CNN
	1    5250 4200
	0    1    1    0   
$EndComp
$Comp
L Device:C C?
U 1 1 5F1FA385
P 5750 4550
AR Path="/5F1223E3/5F1FA385" Ref="C?"  Part="1" 
AR Path="/5F122414/5F1FA385" Ref="C5"  Part="1" 
F 0 "C5" V 5498 4550 50  0000 C CNN
F 1 "100nF" V 5589 4550 50  0000 C CNN
F 2 "Capacitor_SMD:C_0805_2012Metric_Pad1.15x1.40mm_HandSolder" H 5788 4400 50  0001 C CNN
F 3 "~" H 5750 4550 50  0001 C CNN
	1    5750 4550
	0    1    1    0   
$EndComp
Wire Wire Line
	5600 3750 5500 3750
Wire Wire Line
	5500 3750 5500 4200
Wire Wire Line
	5500 4200 5600 4200
Wire Wire Line
	5500 4200 5400 4200
Connection ~ 5500 4200
Wire Wire Line
	5000 4200 5100 4200
Wire Wire Line
	5500 4550 5500 4200
Wire Wire Line
	5500 4550 5600 4550
Wire Wire Line
	5900 4200 6000 4200
Wire Wire Line
	6000 4200 6000 4550
Wire Wire Line
	6000 4550 5900 4550
$Comp
L power:GND #PWR0113
U 1 1 5F1FF8AE
P 6000 4650
F 0 "#PWR0113" H 6000 4400 50  0001 C CNN
F 1 "GND" H 6005 4477 50  0000 C CNN
F 2 "" H 6000 4650 50  0001 C CNN
F 3 "" H 6000 4650 50  0001 C CNN
	1    6000 4650
	1    0    0    -1  
$EndComp
Wire Wire Line
	6000 4650 6000 4550
Connection ~ 6000 4550
$Comp
L power:+3.3V #PWR0114
U 1 1 5F1FFE3B
P 5000 4100
F 0 "#PWR0114" H 5000 3950 50  0001 C CNN
F 1 "+3.3V" H 5015 4273 50  0000 C CNN
F 2 "" H 5000 4100 50  0001 C CNN
F 3 "" H 5000 4100 50  0001 C CNN
	1    5000 4100
	1    0    0    -1  
$EndComp
Wire Wire Line
	5000 4100 5000 4200
Text HLabel 4500 3550 0    50   Input ~ 0
dry_audio_input
Wire Wire Line
	4700 3550 4600 3550
Wire Wire Line
	5000 3550 5100 3550
Text HLabel 6250 3550 2    50   Output ~ 0
buffered_dry_audio
$Comp
L Device:C C4
U 1 1 5F208860
P 4850 3550
F 0 "C4" V 4598 3550 50  0000 C CNN
F 1 "220nF" V 4689 3550 50  0000 C CNN
F 2 "Capacitor_THT:C_Rect_L7.0mm_W3.5mm_P5.00mm" H 4888 3400 50  0001 C CNN
F 3 "~" H 4850 3550 50  0001 C CNN
	1    4850 3550
	0    1    1    0   
$EndComp
$Comp
L Device:R_POT RV1
U 1 1 5F20CAF4
P 5850 3300
F 0 "RV1" V 6050 3550 50  0000 C CNN
F 1 "1M" V 5850 3300 50  0000 C CNN
F 2 "Potentiometer_THT:Potentiometer_Alpha_RD901F-40-00D_Single_Vertical" H 5850 3300 50  0001 C CNN
F 3 "~" H 5850 3300 50  0001 C CNN
	1    5850 3300
	0    -1   -1   0   
$EndComp
Wire Wire Line
	5850 3150 5850 3050
Wire Wire Line
	5850 3050 6100 3050
Wire Wire Line
	6100 3050 6100 3300
Connection ~ 6100 3300
Wire Wire Line
	6100 3300 6000 3300
Text Notes 5500 3250 0    50   ~ 0
gain
Text Notes 3750 2650 0    157  ~ 0
Variable gain input amplifier
$Comp
L Device:R R?
U 1 1 5F2AE6A2
P 4600 3800
AR Path="/5F1223E3/5F2AE6A2" Ref="R?"  Part="1" 
AR Path="/5F122414/5F2AE6A2" Ref="R5"  Part="1" 
F 0 "R5" H 4450 3800 50  0000 L CNN
F 1 "1M" V 4600 3750 50  0000 L CNN
F 2 "Resistor_SMD:R_0805_2012Metric_Pad1.15x1.40mm_HandSolder" V 4530 3800 50  0001 C CNN
F 3 "~" H 4600 3800 50  0001 C CNN
	1    4600 3800
	-1   0    0    1   
$EndComp
Wire Wire Line
	4600 3650 4600 3550
Wire Wire Line
	4600 3550 4500 3550
Connection ~ 4600 3550
$Comp
L power:GND #PWR0115
U 1 1 5F2B11E6
P 4600 3950
F 0 "#PWR0115" H 4600 3700 50  0001 C CNN
F 1 "GND" H 4605 3777 50  0000 C CNN
F 2 "" H 4600 3950 50  0001 C CNN
F 3 "" H 4600 3950 50  0001 C CNN
	1    4600 3950
	1    0    0    -1  
$EndComp
$EndSCHEMATC
