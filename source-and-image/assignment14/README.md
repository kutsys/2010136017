Lab-14 : ELF 파일분석</br>
1. ELF 파일을 분석하여 ELF header, Program header table, Section header table
내용을 화면에 표시한다. 프로그램명은 elfreader, 분석할 ELF파일을 파라미터로
주어지며, 옵션은 e(ELF header), p(program header table), s(section header
table)이며, 동시에 사용가능하다. $ elfreader xxx.elf // ELF header만 표시</br>
$ elfreader –e xxx.elf // ELF header만 표시</br>
$ elfreader –ep xxx.elf // ELF header + program header table 표시</br>
$ elfreader –eps xxx.elf // ELF header + program header table + section header
table 표시</br>
기타 다른 옵션 조합도 가능.</br>
