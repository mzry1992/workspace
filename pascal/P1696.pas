var
        st:ansistring;
function        cf(st:ansistring):boolean; {�ж������������Ƿ���}
begin
        if st[1] = '[' then     exit(true);{��������}
        exit(false);{�Ƿ���}
end;
function        gcd(a,b:longint):longint;
begin
        if b = 0 then   exit(a);
        exit(gcd(b,a mod b));
end;
procedure       solve1(st:ansistring);//������ת��Ϊ����
var
        l,i,j,fm,fz,tnum,zs,tot,tfm,tfz,mgcd:longint;
        num:ansistring;
        a:array[1..200] of longint;//�������
begin
        st := copy(st,2,length(st)-2);
        if st = '0' then {�����������}
        begin
                writeln('0');
                exit;
        end;
        if pos(';',st) = 0 then {�����������}
        begin
                writeln(st);
                exit;
        end;
        num := copy(st,1,pos(';',st)-1); {������������}
        val(num,zs);
        st := copy(st,pos(';',st)+1,length(st)-pos(';',st))+',';
        tot := 0;
        repeat {�������λ��}
                l := length(st);
                num := copy(st,1,pos(',',st)-1);
                st := copy(st,pos(',',st)+1,length(st)-pos(',',st));
                val(num,tnum);
                inc(tot);
                a[tot] := tnum;
        until   st = '';
        fz := 1;        fm := a[tot];
        for i := tot-1 downto 1 do {ͳһ����,fz�����,fm���ĸ}
        begin
                tfz := fm;
                tfm := a[i]*fm+fz;
                mgcd := gcd(tfz,tfm);{�ǵ�ҪԼ��}
                tfz := tfz div mgcd;
                tfm := tfm div mgcd;
                fz := tfz;
                fm := tfm;
        end;
        fz := fm*zs+fz;
        mgcd := gcd(fz,fm);{��Լһ�η�}
        fz := fz div mgcd;
        fm := fm div mgcd;
        writeln(fz,'/',fm);{���}
end;
procedure       solve2(st:ansistring);//����ת������
var
        zs,l,tot,fz,fm,x,y,z,i,mgcd:longint;
        sfz,sfm:ansistring;
        a:array[1..200] of longint;
begin
        sfz := copy(st,1,pos('/',st)-1);{�ҵ�����}
        sfm := copy(st,pos('/',st)+1,length(st)-pos('/',st));{�ҵ���ĸ}
        val(sfz,fz);    val(sfm,fm);
        mgcd := gcd(fz,fm);{�ȸ����ӷ�ĸԼ�·�}
        fz := fz div mgcd;
        fm := fm div mgcd;
        zs := fz div fm;
        fz := fz mod fm;
        if fz = 0 then
        begin
                writeln('[',zs,']');{�������Ϊ0,ֱ���������,��5/1,Լ�ֺ�zs=5,fz=0,ֱ�����[5]}
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
                        fz := z;        {Ȼ��������� z/x,��y�������} 
                        fm := x;
                until   fz = 1;
        end;
        inc(tot);
        a[tot] := fm;
        write('[',zs,';');{���������}
        for i := 1 to tot-1 do{�����С��}
                write(a[i],',');
        writeln(a[tot],']');{���һ��]}
end;
begin
        while not eof do
        begin
                readln(st);
                if cf(st) then solve1(st)
                else    solve2(st);
        end;
end.
