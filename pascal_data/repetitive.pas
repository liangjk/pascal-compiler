program rep;

const one=1,two=2,five=5;ten=10;
var i,j,flag;
	a:array[0..five,0..3] of integer;
	cnt;

begin
for i:=0 to 5 do
	begin
		writeln(i);
	end;
cnt:=1;
for i:=five downto 0 do
	begin
	for j:=0 to 3 do
		begin
		write(i);
		write(' ');
		writeln(j);
		a[i,j]:=cnt;
		cnt:=cnt+1;
		end;
	end;
for i:=0 to 5 do
	begin
	for j:=0 to 3 do
		begin
		write(a[i,j]);
		write(' ');
		end;
	writeln();
	end;

i:=1;
while((i<=256) and not odd(flag))do
	begin
		i:=i*2;
		writeln(i);
		read(flag);
	end;

read(i);
repeat
	i:=i div 2;
	writeln(i);
until
	i<=0;

end.