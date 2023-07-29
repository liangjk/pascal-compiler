program rec;

type arr=array [0..3] of integer,
	rec=record a:arr;b:real; end;

var x:rec;y:integer;

begin
	x.a[0]:=0;
	x.a[1]:=1;
	x.a[2]:=2;
	x.a[3]:=3;
	x.b:=3.14;
	x.b:=x.b/2.0;
	read(y);
	writeln(x.a[y]);
	writeln(x.b);
end.