sort $1 > $1.sort
sort $2 > $2.sort
diff $1.sort $2.sort | grep ^[\>\<] | wc -l

