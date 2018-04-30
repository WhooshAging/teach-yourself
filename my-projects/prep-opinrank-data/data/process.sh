#! /bin/bash

cd 'in'
n=1;
for i in * 
do
	grep '^<TEXT>' "$i" | sed 's/<TEXT>//g' | sed 's/<\/TEXT>//g' > "$n"'.txt';
	n=$((n+1));
done
mv *.txt ../out
