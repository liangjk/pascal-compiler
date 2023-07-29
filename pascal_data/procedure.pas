program pro;

var x;

procedure test1(y:integer;);
	begin
	writeln(x);
	writeln(y);
	end;

procedure test2(y:integer;);
	begin
	writeln(x+x);
	y:=2*y;
	writeln(y);
	test1(3*y);
	writeln('-');
	end;

procedure dg(z:integer;);
	begin
	write('+');
	writeln(x);
	writeln(z);
	if(z>0)then
		begin
			dg(z-1);
		end;
	end;

begin
read(x);
test2(x);
test1(x);
dg(x);
end.