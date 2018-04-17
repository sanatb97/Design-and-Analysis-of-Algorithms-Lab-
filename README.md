# Design-and-Analysis-of-Algorithms-Lab-
Practical Programs as a part of my course in Design and Analysis of Algorithms-Lab 

*How to build an executable from 3-file approach?
<ul>
	<li>
a. Compile to generate ss.o object file <br>
	gcc -Wall ss.c -c </li><br>
	<li>
b. Compile to generate the executable file ss_client.out <br>
	gcc -Wall ss_client.c ss.o -o ss_client.out -lrt </li><br>
	<li>
c. Execute by feeding the input file ss_ip1.txt and output written to tmp <br>
	./ss_client.out < s2_ip1.txt > tmp </li><br>
		<li>
d. Test for correctness with the expected output <br>
diff -wB tmp ss_op1.txt
	</li>
