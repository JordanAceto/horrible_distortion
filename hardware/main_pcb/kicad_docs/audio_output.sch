EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 4 7
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
U 1 1 5F21B31A
P 5200 3900
AR Path="/5F1223E3/5F21B31A" Ref="R?"  Part="1" 
AR Path="/5F122414/5F21B31A" Ref="R?"  Part="1" 
AR Path="/5F122464/5F21B31A" Ref="R10"  Part="1" 
F 0 "R10" V 5100 3850 50  0000 L CNN
F 1 "8k2" V 5200 3800 50  0000 L CNN
F 2 "Resistor_SMD:R_0805_2012Metric_Pad1.15x1.40mm_HandSolder" V 5130 3900 50  0001 C CNN
F 3 "~" H 5200 3900 50  0001 C CNN
	1    5200 3900
	0    1    1    0   
$EndComp
$Comp
L Amplifier_Operational:MCP6002-xP U?
U 2 1 5F21B327
P 6300 4000
AR Path="/5F1223E3/5F21B327" Ref="U?"  Part="1" 
AR Path="/5F122414/5F21B327" Ref="U?"  Part="1" 
AR Path="/5F122464/5F21B327" Ref="U1"  Part="2" 
F 0 "U1" H 6150 4400 50  0000 C CNN
F 1 "MCP6002-xP" H 6350 4300 50  0000 C CNN
F 2 "Package_SO:SOIC-8_3.9x4.9mm_P1.27mm" H 6300 4000 50  0001 C CNN
F 3 "http://ww1.microchip.com/downloads/en/DeviceDoc/21733j.pdf" H 6300 4000 50  0001 C CNN
	2    6300 4000
	1    0    0    -1  
$EndComp
Text HLabel 4450 3900 0    50   Input ~ 0
wet_from_DAC
Wire Wire Line
	4550 3900 4450 3900
Wire Wire Line
	4950 3900 5050 3900
Text HLabel 7600 4000 2    50   Output ~ 0
buffered_wet_audio
$Comp
L Device:C C?
U 1 1 5F2243B2
P 5450 4150
AR Path="/5F122414/5F2243B2" Ref="C?"  Part="1" 
AR Path="/5F122464/5F2243B2" Ref="C7"  Part="1" 
F 0 "C7" H 5300 4100 50  0000 R CNN
F 1 "1nF" H 5300 4200 50  0000 R CNN
F 2 "Capacitor_SMD:C_0805_2012Metric_Pad1.15x1.40mm_HandSolder" H 5488 4000 50  0001 C CNN
F 3 "~" H 5450 4150 50  0001 C CNN
	1    5450 4150
	-1   0    0    1   
$EndComp
$Comp
L Device:C C?
U 1 1 5F227302
P 5200 3450
AR Path="/5F122414/5F227302" Ref="C?"  Part="1" 
AR Path="/5F122464/5F227302" Ref="C6"  Part="1" 
F 0 "C6" V 4948 3450 50  0000 C CNN
F 1 "1nF" V 5039 3450 50  0000 C CNN
F 2 "Capacitor_SMD:C_0805_2012Metric_Pad1.15x1.40mm_HandSolder" H 5238 3300 50  0001 C CNN
F 3 "~" H 5200 3450 50  0001 C CNN
	1    5200 3450
	0    1    1    0   
$EndComp
$Comp
L Device:R R?
U 1 1 5F2279EC
P 4700 3900
AR Path="/5F1223E3/5F2279EC" Ref="R?"  Part="1" 
AR Path="/5F122414/5F2279EC" Ref="R?"  Part="1" 
AR Path="/5F122464/5F2279EC" Ref="R9"  Part="1" 
F 0 "R9" V 4600 3850 50  0000 L CNN
F 1 "8k2" V 4700 3800 50  0000 L CNN
F 2 "Resistor_SMD:R_0805_2012Metric_Pad1.15x1.40mm_HandSolder" V 4630 3900 50  0001 C CNN
F 3 "~" H 4700 3900 50  0001 C CNN
	1    4700 3900
	0    1    1    0   
$EndComp
Wire Wire Line
	4950 3900 4950 3450
Wire Wire Line
	4950 3450 5050 3450
Wire Wire Line
	4950 3900 4850 3900
Connection ~ 4950 3900
Wire Wire Line
	5350 3900 5450 3900
Wire Wire Line
	5450 4000 5450 3900
Connection ~ 5450 3900
Wire Wire Line
	5450 3900 6000 3900
Wire Wire Line
	6600 4000 6700 4000
Wire Wire Line
	6700 4000 6700 3450
Wire Wire Line
	6700 3450 5350 3450
Connection ~ 6700 4000
Wire Wire Line
	6000 4100 5900 4100
$Comp
L power:GND #PWR?
U 1 1 5F230506
P 5450 4300
AR Path="/5F122414/5F230506" Ref="#PWR?"  Part="1" 
AR Path="/5F122464/5F230506" Ref="#PWR0116"  Part="1" 
F 0 "#PWR0116" H 5450 4050 50  0001 C CNN
F 1 "GND" H 5455 4127 50  0000 C CNN
F 2 "" H 5450 4300 50  0001 C CNN
F 3 "" H 5450 4300 50  0001 C CNN
	1    5450 4300
	1    0    0    -1  
$EndComp
$Comp
L Device:CP1 C8
U 1 1 5F233DF9
P 7250 4000
F 0 "C8" V 7502 4000 50  0000 C CNN
F 1 "10uF" V 7411 4000 50  0000 C CNN
F 2 "Capacitor_THT:CP_Radial_D6.3mm_P2.50mm" H 7250 4000 50  0001 C CNN
F 3 "~" H 7250 4000 50  0001 C CNN
	1    7250 4000
	0    -1   -1   0   
$EndComp
$Comp
L Device:R R?
U 1 1 5F234BA2
P 6950 4000
AR Path="/5F1223E3/5F234BA2" Ref="R?"  Part="1" 
AR Path="/5F122414/5F234BA2" Ref="R?"  Part="1" 
AR Path="/5F122464/5F234BA2" Ref="R11"  Part="1" 
F 0 "R11" V 6850 3950 50  0000 L CNN
F 1 "560" V 6950 3900 50  0000 L CNN
F 2 "Resistor_SMD:R_0805_2012Metric_Pad1.15x1.40mm_HandSolder" V 6880 4000 50  0001 C CNN
F 3 "~" H 6950 4000 50  0001 C CNN
	1    6950 4000
	0    1    1    0   
$EndComp
Wire Wire Line
	6800 4000 6700 4000
Wire Wire Line
	5900 4100 5900 4450
Wire Wire Line
	5900 4450 6700 4450
Wire Wire Line
	6700 4450 6700 4000
Text Notes 3650 2950 0    157  ~ 0
20kHz Low-pass filter/output buffer
$Comp
L Device:R R?
U 1 1 5F2B311E
P 7500 4250
AR Path="/5F1223E3/5F2B311E" Ref="R?"  Part="1" 
AR Path="/5F122414/5F2B311E" Ref="R?"  Part="1" 
AR Path="/5F122464/5F2B311E" Ref="R12"  Part="1" 
F 0 "R12" H 7300 4250 50  0000 L CNN
F 1 "1M" V 7500 4200 50  0000 L CNN
F 2 "Resistor_SMD:R_0805_2012Metric_Pad1.15x1.40mm_HandSolder" V 7430 4250 50  0001 C CNN
F 3 "~" H 7500 4250 50  0001 C CNN
	1    7500 4250
	-1   0    0    1   
$EndComp
$Comp
L power:GND #PWR?
U 1 1 5F2B3124
P 7500 4400
AR Path="/5F122414/5F2B3124" Ref="#PWR?"  Part="1" 
AR Path="/5F122464/5F2B3124" Ref="#PWR0117"  Part="1" 
F 0 "#PWR0117" H 7500 4150 50  0001 C CNN
F 1 "GND" H 7505 4227 50  0000 C CNN
F 2 "" H 7500 4400 50  0001 C CNN
F 3 "" H 7500 4400 50  0001 C CNN
	1    7500 4400
	1    0    0    -1  
$EndComp
Wire Wire Line
	7600 4000 7500 4000
Wire Wire Line
	7500 4100 7500 4000
Connection ~ 7500 4000
Wire Wire Line
	7500 4000 7400 4000
$EndSCHEMATC
