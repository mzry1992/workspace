var
        st:ansistring;
function        cf(st:ansistring):boolean; {判断是连分数还是分数}
begin
        if st[1] = '[' then     exit(true);{是连分数}
        exit(false);{是分数}
end;
function        gcd(a,b:longint):longint;
begin
        if b = 0 then   exit(a);
        exit(gcd(b,a mod b));
end;
procedure       solve1(st:ansistring);//连分数转换为分数
var
        l,i,j,fm,fz,tnum,zs,tot,tfm,tfz,mgcd:longint;
        num:ansistring;
        a:array[1..200] of longint;//存各个项
begin
        st := copy(st,2,length(st)-2);
        if st = '0' then {几个特殊情况}
        begin
                writeln('0');
                exit;
        end;
        if pos(';',st) = 0 then {几个特殊情况}
        begin
                writeln(st);
                exit;
        end;
        num := copy(st,1,pos(';',st)-1); {分离整数部分}
        val(num,zs);
        st := copy(st,pos(';',st)+1,length(st)-pos(';',st))+',';
        tot := 0;
        repeat {分离各个位数}
                l := length(st);
                num := copy(st,1,pos(',',st)-1);
                st := copy(st,pos(',',st)+1,length(st)-pos(',',st));
                val(num,tnum);
                inc(tot);
                a[tot] := tnum;
        until   st = '';
        fz := 1;        fm := a[tot];
        for i := tot-1 downto 1 do {统一计算,fz存分子,fm存分母}
        begin
                tfz := fm;
                tfm := a[i]*fm+fz;
                mgcd := gcd(tfz,tfm);{记得要约分}
                tfz := tfz div mgcd;
                tfm := tfm div mgcd;
                fz := tfz;
                fm := tfm;
        end;
        fz := fm*zs+fz;
        mgcd := gcd(fz,fm);{再约一次分}
        fz := fz div mgcd;
        fm := fm div mgcd;
        writeln(fz,'/',fm);{输出}
end;
procedure       solve2(st:ansistring);//分数转连分数
var
        zs,l,tot,fz,fm,x,y,z,i,mgcd:longint;
        sfz,sfm:ansistring;
        a:array[1..200] of longint;
begin
        sfz := copy(st,1,pos('/',st)-1);{找到分子}
        sfm := copy(st,pos('/',st)+1,length(st)-pos('/',st));{找到分母}
        val(sfz,fz);    val(sfm,fm);
        mgcd := gcd(fz,fm);{先给分子分母约下分}
        fz := fz div mgcd;
        fm := fm div mgcd;
        zs := fz div fm;
        fz := fz mod fm;
        if fz = 0 then
        begin
                writeln('[',zs,']');{如果分子为0,直接输出整数,如5/1,约分后zs=5,fz=0,直接输出[5]}
                exit;
        end;
        tot := 0;
        if fz <> 1 then
        begin
                repeat
                        x := fz;        {    x           1    }
                        y := fm div fz; { ------- --> ------- }
                        z := fm mod fz; { x*y + z          z  }
                        inc(tot);       {              y + -  }
                        a[tot] := y;    {                  x  }  
                        fz := z;        {然后继续处理 z/x,将y加入答案中} 
                        fm := x;
                until   fz = 1;
        end;
        inc(tot);
        a[tot] := fm;
        write('[',zs,';');{先输出整数}
        for i := 1 to tot-1 do{再输出小数}
                write(a[i],',');
        writeln(a[tot],']');{最后一个]}
end;
begin
        while not eof do
        begin
                readln(st);
                if cf(st) then solve1(st)
                else    solve2(st);
        end;
end.
