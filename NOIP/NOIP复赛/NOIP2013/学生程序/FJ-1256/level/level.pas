var n,m,i,j,k:longint;
    s:array[1..1000] of longint;
begin
  assign(input,'level.in');
  reset(input);
  assign(output,'level.out');
  rewrite(output);
  readln(n,m);
  for i:=1 to m do
      begin
        read(k);
        for j:=1 to k do read(s[j]);
        readln;
      end;
  writeln(m);
  close(input);
  close(output);
end.
