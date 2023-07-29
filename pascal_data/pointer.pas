program pointer;

const up=5;

type pt=^integer;

var arr:array[1..up] of integer;ptr:pt;i:integer;
rec:record a,b:integer; end;

procedure print;
begin
for i:=1 to up do
	begin
	write(arr[i]);
	write(' ');
	end;
writeln();
end;

begin
for i:=1 to up do
	begin
	arr[i]:=i;
	end;
	
call print;

ptr:=^arr[3];
^ptr:=1-20;

call print;

rec.a:=0;
rec.b:=0;
ptr:=^rec.a;
^ptr:=1;
ptr:=^rec.b;
^ptr:=2;
write(rec.a);
write(' ');
writeln(rec.b);

end.