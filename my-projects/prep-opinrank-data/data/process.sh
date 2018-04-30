#! /bin/bash

cd 'in'
for i in * 
do
	grep '^<TEXT>' "$i" | sed 's/<TEXT>//g' | sed 's/<\/TEXT>//g' > "$i"'.txt';
done
mv *.txt ../out
