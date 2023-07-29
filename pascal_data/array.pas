program arr;

type arr=array[1..3] of integer;

var a:arr;
	b:array[0..2,0..3] of real;
	x,y;

begin
	a[1]:=1;
	a[2]:=2;
	a[3]:=3;
	read(x);
	writeln(a[x]);
	b[0,0]:=0.0;
	b[0,1]:=0.1;
	b[0,2]:=0.2;
	b[0,3]:=0.3;
	b[1,0]:=1.0;
	b[1,1]:=1.1;
	b[1,2]:=1.2;
	b[1,3]:=1.3;
	b[2,0]:=2.0;
	b[2,1]:=2.1;
	b[2,2]:=2.2;
	b[2,3]:=2.3;
	read(x);
	read(y);
	writeln(b[x,y]);
end.
		