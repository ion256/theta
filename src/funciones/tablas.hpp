// middle C (261,63Hz) corresponds to do', in the fifth line, third octave if we count the zero octave
char tabladenotas[][9]={
"la,,,", "las,,,", "si,,,",
"do,,", "dos,,", "re,,", "res,,", "mi,,", "fa,,", "fas,,", "sol,,", "sols,,", "la,,", "las,,", "si,,",
"do,", "dos,", "re,", "res,", "mi,", "fa,", "fas,", "sol,", "sols,", "la,", "las,", "si,",
"do", "dos", "re", "res", "mi", "fa", "fas", "sol", "sols", "la", "las", "si",
"do'", "dos'", "re'", "res'", "mi'", "fa'", "fas'", "sol'", "sols'", "la'", "las'", "si'",
"do''", "dos''", "re''", "res''", "mi''", "fa''", "fas''", "sol''", "sols''", "la''", "las''", "si''",
"do'''", "dos'''", "re'''", "res'''", "mi'''", "fa'''", "fas'''", "sol'''", "sols'''", "la'''", "las'''", "si'''",
"do''''", "dos''''", "re''''", "res''''", "mi''''", "fa''''", "fas''''", "sol''''", "sols''''", "la''''", "las''''", "si''''",
"do'''''"
};

//these are the valid intervals for major diatonic scales. The first value is used as the limit of the counter in pertenece
int intdiamayor[]={
60,-39,-37,-36,-34,-32,-31,-29,-27,-25,-24,-22,-20,-19,-17,-15,-13,-12,-10,-8,-7,-5,-3,-1,0,2,4,5,7,
9,11,12,14,16,17,19,21,23,24,26,28,29,31,33,35,36,38,40,41,43,45,47,48,50,52,53,55,57,59,60,
};

//these are for minor diatonic.
int intdiamenor[]={
59,-38,-36,-34,-33,-31,-29,-28,-26,-24,-22,-21,-19,-17,-16,-14,-12,-10,-9,-7,-5,-4,-2,0,2,3,5,7,8,10,12
,14,15,17,19,20,22,24,26,27,29,31,32,34,36,38,39,41,43,44,46,48,50,51,53,55,56,58,60,
};
