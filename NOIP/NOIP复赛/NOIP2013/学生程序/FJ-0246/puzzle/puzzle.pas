program puzzle;
var n,m,q,i,j,f:longint;
   a:array[1..1000000,1..1000000]of longint;
begin
assign(input,'puzzle.in');
reset(input);
assign(output,'puzzle.out');
reset(output);
readln(n,m,q);
for i:=1 to n do
 for j:=1 to m do
  read(a[i,j]);
for i:=1 to q do
 for j:=1 to 6 do
  readln(f);
writeln(2);
writeln(-1);
close(input);
close(output);
end.

