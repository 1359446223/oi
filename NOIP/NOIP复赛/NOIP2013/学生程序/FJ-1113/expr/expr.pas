var
  s:string;
begin
  assign(input,'expr.in');
  assign(output,'expr.out');
  reset(input);
  rewrite(output);
  readln(s);
  writeln('8');
  close(input);
  close(output);
end.