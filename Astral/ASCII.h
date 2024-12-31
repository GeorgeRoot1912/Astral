#ifndef ASTRAL_ASCII_H_
#define ASTRAL_ASCII_H_ 1
#define _NUL 0
#define _SOH 1
#define _STX 2
#define _ETX 3
#define _EOT 4
#define _ENQ 5
#define _ACK 6
#define _BEL 7
#define _BS 8
#define _HT 9
#define _LF 10
#define _VT 11
#define _FF 12
#define _CR 13 
#define _SO 14 
#define _SI 15 
#define _DLE 16
#define _DC1 17
#define _DC2 18
#define _DC3 19
#define _DC4 20
#define _NAK 21 
#define _SYN 22
#define _ETB 23 
#define _CAN 24
#define _EM 25 
#define _SUB 26
#define _ESC 27
#define _FS 28
#define _GC 29
#define _RS 30
#define _US  31
#define _DEL 127
#define _SPACE 32
#define _NBSP 160
#define _SHY 255
#define _Ctrl_Z 26
#define _Ctrl_Y 25
#define _Ctrl_X 24
#define _Ctrl_W 23
#define _Ctrl_V 22
#define _Ctrl_U 21
#define _Ctrl_T 20
#define _Ctrl_S 19
#define _Ctrl_R 18
#define _Ctrl_Q 17
#define _Ctrl_P 16
#define _Ctrl_O 15
#define _Ctrl_N 14
#define _Ctrl_M 13
#define _Ctrl_L 12
#define _Ctrl_K 11
#define _Ctrl_J 10
#define _Ctrl_I 9
#define _Ctrl_H 8
#define _Ctrl_G 7
#define _Ctrl_F 6
#define _Ctrl_E 5
#define _Ctrl_D 4
#define _Ctrl_C 3 
#define _Ctrl_B 2
#define _Ctrl_A 1
#define _PAD 128
#define _HOP 129
#define _BPH 130
#define _NPH 131
#define _IND 132
#define _NEL 133
#define _SSA 134
#define _ESA 135 
#define  _HTS 136 
#define _HTJ 137 
#define _VTS 138 
#define _PLD 139
#define _PLU 140
#define _RI 141
#define _SS2 142 
#define _SS3 143
#define _DCS 144
#define _PU1 145
#define _Pu2 146
#define _STS 147
#define _CCH 148
#define _MV 149
#define _SPA 150
#define _EPA 151
#define _SOS 152
#define _SGCI 153 
#define _SCI 154
#define _CSI 155
#define _ST 156
#define _OSC 157
#define _PM 158
#define _APC 159
#define _UHB "▀"
#define _LOEB "▁"
#define _LOQB "▂"
#define _LTEB "▃"
#define _LHB "▄"
#define _LFEB "▅"
#define _LTQB "▆"
#define _LSEB "▇"
#define _FB "█"
#define _LEFTFEV "▋"
#define _LEFTHB "▌"
#define _LEFTQB "▎"
#define _RHB "▐"
#define _LIS "░"
#define _MES "▒"
#define _DAH "▓"
#define _ROEB "▕ "
#define _QLL "▖"
#define _QLR "▗"
#define _QUL "▘"
#define _QULL "▙"
#define _BSQ "■"
#define _BUP "▲"
#define _BRP "▶"
#define _BDP "▼"
#define _BLP "◀"
#define _BDIAM "◆"
// ASCII (TEST)
int IsPrintable(unsigned int __char){
    if (__char < 32){return -1; } // NOT
    if (__char > 127 && __char < 160){
        return -1; // Not
    }
    return 0; // Printable
}
int IsControl(unsigned int __char){
    if (IsPrintable(__char) == 0){return -1;} // Not 
    return 0; // Control
}
int Isspace(unsigned int __char){
    if ( __char == 32 || __char == 11 || __char == 10 || __char == 9){return 0;}
    return -1;
}
int IsGraph(unsigned int __char ){
    if (Isspace(__char) == -1 && IsControl(__char) == -1){
        return 0;
    } return -1;
}
int IsNum(unsigned int __char){
    if (__char > 47 && __char < 58){
        return 0; // NUM
    }
    return -1;
}
int IsHexNum(unsigned int __char){
    if (__char > 64 && __char < 71 ){
        return 0;
    }
    if (__char > 96 && __char < 103){
        return 0;
    }
    if (__char > 47 && __char < 58){
        return 0;
    }
    return -1;
}
int IsBinNum(unsigned int __char){
    if (__char == 48 || __char == 49){
        return 0;
    }
    return -1;
}
int IsOctNum(unsigned int __char){
    if (__char > 47 && __char < 56){
        return 0;
    } 
    return -1;
}
int IsLet(unsigned int __char){
    if (IsGraph(__char) == 0 && IsNum(__char) == -1){
        return 0;
    }
    return -1;
}
int IsPunct(unsigned int __char){
    if (__char > 32 && __char < 48){
        return 0;
    }
    if (__char > 57 && __char < 65){
        return 0;
    }
    if (__char > 90 && __char < 97){
        return 0;
    }
    if (__char > 160 && __char < 192){
        return 0;
    }
    if (__char > 122 && __char < 127){
        return 0;
    }
    return -1;
}
#endif // !ASTRAL_ASCII_H_