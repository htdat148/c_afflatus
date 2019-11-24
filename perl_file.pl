#1/usr/local/bin/perl

$size = 10;
open(INFILE, "file.txt");
$#arr = $size - 1; 		# initilize the size off array
$i = 0;

foreach $line (<INFILE>){
    $arr[$i] = $line;
    print "$arr[$i]\n";
    $i++;
    
    if( $i >= $size){
	$#arr = 2*$#arr + 1;
	$size = $#arr + 1;
}
    
}

