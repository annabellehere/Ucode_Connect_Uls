#include "../inc/uls.h"

void mx_check_flags(t_flags *flag, char **argv, int argc) {
    for (int j = 1; j < argc; j++){
        if (argv[j][0] != '-'){
            break;
        }
        for (int i = 1; i < mx_strlen(argv[j]); i++) {
            switch(argv[j][i]) {
                case 'l':
                    flag->l_flag = true;
                    break;
                case 'a':
                    flag->a_flag = true;
                    break;
                case 'R':
                    flag->R_flag = true;
                    break;
                case 'A':
                    flag->A_flag = true;
                    break;
                case 'G':
                    flag->G_flag = true;
                    break;
                case 'h':
                    flag->h_flag = true;
                    break;
                case '@':
                    flag->sob_flag = true;
                    break;
                case 'e':
                    flag->e_flag = true;
                    break;
                case 'T':
                    flag->T_flag = true;
                    break;
                case 'i':
                    flag->i_flag = true;
                    break;
                case 'C':
                    flag->C_flag = true;
                    break;
                case 'r':
                    flag->r_flag = true;
                    break;
                case 't':
                    flag->t_flag = true;
                    break;
                case 'u':
                    flag->u_flag = true;
                    break;;
                case 'c':
                    flag->c_flag = true;
                    break;
                case '1':
                    flag->one_flag = true;
                    break;
                case 'm':
                    flag->m_flag = true;
                    break;
                case 'p':
                    flag->p_flag = true;
                    break;
                case 'f':
                    flag->f_flag = true;
                    break;    
                case 'S':
                    flag->S_flag = true;
                    break;
                case 'F':
                    flag->F_flag = true;
                    break;
            }    
        }
    }
}

