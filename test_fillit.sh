echo "test error_0:"
./fillit ./testsrcs/error_0 | sed 's|error|OK|g'
echo "test error_1:"
./fillit ./testsrcs/error_1 | sed 's|error|OK|g'
echo "test error_2:"
./fillit ./testsrcs/error_2 | sed 's|error|OK|g'
echo "test error_3:"
./fillit ./testsrcs/error_3 | sed 's|error|OK|g'
echo "test error_4:"
./fillit ./testsrcs/error_4 | sed 's|error|OK|g'
echo "test error_5:"
./fillit ./testsrcs/error_5 | sed 's|error|OK|g'
echo "test error_6:"
./fillit ./testsrcs/error_6 | sed 's|error|OK|g'
echo "test error_7:"
./fillit ./testsrcs/error_7 | sed 's|error|OK|g'
echo "test error_8:"
./fillit ./testsrcs/error_8 | sed 's|error|OK|g'
echo "test error_9:"
./fillit ./testsrcs/error_9 | sed 's|error|OK|g'
echo "test error_10:"
./fillit ./testsrcs/error_10 | sed 's|error|OK|g'
echo "test error_11:"
./fillit ./testsrcs/error_11 | sed 's|error|OK|g'
echo "test error_12:"
./fillit ./testsrcs/error_12 | sed 's|error|OK|g'
echo "test error_13:"
./fillit ./testsrcs/error_13 | sed 's|error|OK|g'
echo "test error_14:"
./fillit ./testsrcs/error_14 | sed 's|error|OK|g'
echo "test error_15:"
./fillit ./testsrcs/error_15 | sed 's|error|OK|g'
echo "test error_16:"
./fillit ./testsrcs/error_16 | sed 's|error|OK|g'
echo "test error_17:"
./fillit ./testsrcs/error_17 | sed 's|error|OK|g'
echo "test error_18:"
./fillit ./testsrcs/error_18 | sed 's|error|OK|g'
echo "test error_19:"
./fillit ./testsrcs/error_19 | sed 's|error|OK|g'
echo "test error_20:"
./fillit ./testsrcs/error_20 | sed 's|error|OK|g'
echo "test error_21:"
./fillit ./testsrcs/error_21 | sed 's|error|OK|g'
echo "test error_22:"
./fillit ./testsrcs/error_22 | sed 's|error|OK|g'
echo "test error_23:"
./fillit ./testsrcs/error_23 | sed 's|error|OK|g'
echo "test error_24:"
./fillit ./testsrcs/error_24 | sed 's|error|OK|g'
echo "test error_25:"
./fillit ./testsrcs/error_25 | sed 's|error|OK|g'
echo "test error_26:"
./fillit ./testsrcs/error_26 | sed 's|error|OK|g'
echo "test error_27:"
./fillit ./testsrcs/error_27 | sed 's|error|OK|g'
echo "test error_28:"
./fillit ./testsrcs/error_28 | sed 's|error|OK|g'
echo "test error_29:"
./fillit ./testsrcs/error_29 | sed 's|error|OK|g'
echo "test error_30:"
./fillit ./testsrcs/error_30 | sed 's|error|OK|g'
echo "test fig_00:"
./fillit ./testsrcs/fig_00 | tr -d '\n' | sed 's|AAAA|OK|g'
echo "test fig_01:"
./fillit ./testsrcs/fig_01 | tr -d '\n' | sed 's|A...A...A...A...|OK|g'
echo "test fig_02:"
./fillit ./testsrcs/fig_02 | tr -d '\n' | sed 's|AAAA............|OK|g'
echo "test fig_03:"
./fillit ./testsrcs/fig_03 | tr -d '\n' | sed 's|A..AAA...|OK|g'
echo "test fig_04:"
./fillit ./testsrcs/fig_04 | tr -d '\n' | sed 's|AAAA.....|OK|g'
echo "test fig_05:"
./fillit ./testsrcs/fig_05 | tr -d '\n' | sed 's|AAA..A...|OK|g'
echo "test fig_06:"
./fillit ./testsrcs/fig_06 | tr -d '\n' | sed 's|..AAAA...|OK|g'
echo "test fig_07:"
./fillit ./testsrcs/fig_07 | tr -d '\n' | sed 's|AA..A..A.|OK|g'
echo "test fig_08:"
./fillit ./testsrcs/fig_08 | tr -d '\n' | sed 's|AA.A..A..|OK|g'
echo "test fig_09:"
./fillit ./testsrcs/fig_09 | tr -d '\n' | sed 's|A..A..AA.|OK|g'
echo "test fig_10:"
./fillit ./testsrcs/fig_10 | tr -d '\n' | sed 's|.A..A.AA.|OK|g'
echo "test fig_11:"
./fillit ./testsrcs/fig_11 | tr -d '\n' | sed 's|AA..AA...|OK|g'
echo "test fig_12:"
./fillit ./testsrcs/fig_12 | tr -d '\n' | sed 's|.AAAA....|OK|g'
echo "test fig_13:"
./fillit ./testsrcs/fig_13 | tr -d '\n' | sed 's|.A.AA.A..|OK|g'
echo "test fig_14:"
./fillit ./testsrcs/fig_14 | tr -d '\n' | sed 's|A..AA..A.|OK|g'
echo "test fig_15:"
./fillit ./testsrcs/fig_15 | tr -d '\n' | sed 's|.A.AA..A.|OK|g'
echo "test fig_16:"
./fillit ./testsrcs/fig_16 | tr -d '\n' | sed 's|A..AA.A..|OK|g'
echo "test fig_17:"
./fillit ./testsrcs/fig_17 | tr -d '\n' | sed 's|AAA.A....|OK|g'
echo "test fig_18:"
./fillit ./testsrcs/fig_18 | tr -d '\n' | sed 's|.A.AAA...|OK|g'
echo "test valid_0:"
./fillit ./testsrcs/valid_0 | tr -d '\n' | sed 's|ABB.ABB.A...A...|OK|g'
echo "test valid_1:"
./fillit ./testsrcs/valid_1 | tr -d '\n' | sed 's|AABB.A.B.A.B....|OK|g'
echo "test valid_2:"
./fillit ./testsrcs/valid_2 | tr -d '\n' | sed 's|AACCAA.CBB.CBB..|OK|g'
echo "test valid_3:"
./fillit ./testsrcs/valid_3 | tr -d '\n' | sed 's|.A.B.AABB..A.B.CC...CC...|OK|g'
echo "test valid_4:"
./fillit ./testsrcs/valid_4 | tr -d '\n' | sed 's|A..B.AABB.AC.B.CC....C...|OK|g'
echo "test valid_5:"
./fillit ./testsrcs/valid_5 | tr -d '\n' | sed 's|ABDDDAB..DAB...AB...CCCC|OK|g'
echo "test valid_6:"
./fillit ./testsrcs/valid_6 | tr -d '\n' | sed 's|AAC.AAC...CCBBBB|OK|g'
echo "test valid_7:"
./fillit ./testsrcs/valid_7 | tr -d '\n' | sed 's|BBBB.AAAA|OK|g'
echo "test valid_8:"
./fillit ./testsrcs/valid_8 | tr -d '\n' | sed 's|AAAB.ABBB|OK|g'
echo "test valid_9:"
./fillit ./testsrcs/valid_9 | tr -d '\n' | sed 's|CC.BACCBA.BBAA..|OK|g'
echo "test valid_10:"
./fillit ./testsrcs/valid_10 | tr -d '\n' | sed 's|ACC.AACCA.B.BBB.|OK|g'
echo "test valid_11:"
./fillit ./testsrcs/valid_11 
echo "test valid_12:"
./fillit ./testsrcs/valid_12 
echo "test valid_13:"
./fillit ./testsrcs/valid_13 
echo "test valid_14:"
./fillit ./testsrcs/valid_14 
echo "test valid_15:"
./fillit ./testsrcs/valid_15 
echo "test valid_16:"
./fillit ./testsrcs/valid_16 
echo "test valid_17:"
./fillit ./testsrcs/valid_17 
echo "test valid_18:"
./fillit ./testsrcs/valid_18 
echo "test valid_19:"
./fillit ./testsrcs/valid_19 
echo "test valid_20:"
./fillit ./testsrcs/valid_20 
echo "test valid_21:"
./fillit ./testsrcs/valid_21
echo "Usage test:"
./fillit 
echo "Простейшие кейсы выдают ОК, а начиная с теста valid_10 - смотрите на вывод и определяйте самостоятельно - корректно или нет"
