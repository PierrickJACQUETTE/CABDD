sort -n $1 > $1.sort
diff $1.sort $2 | grep ^[\>\<] | wc -l

