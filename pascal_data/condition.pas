program cond;

const four=4,five=5;
var x,y,z;

begin
	read(x);
	
	if(x<=10)then
		begin
			writeln('a');
			writeln(x<=10);
		end
	else
		begin
			writeln('b');
			writeln(x<=10);
		end;
	
	read(x);
	read(y);
	
	if((x>=10)and(y<=10))then
		begin
			z:=x*10+y;
		end
	else
		begin
			z:=x+y;
		end;
	
	writeln(z);
	
	read(x);
	
	case x-1 of
		1,2,3:
			begin
				writeln(1);
			end;
		four,five:
			begin
				writeln(2);
			end;
		9,10:
			begin
				writeln(3);
			end;
		else
			begin
				writeln(4);
			end;
		end;
	
	writeln(x);
end.
			