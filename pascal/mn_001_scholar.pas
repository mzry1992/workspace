uses    sysutils;
type
        stud = record
                name:string;
                pj,bj:longint;
                gb,xb:boolean;
                lw,jj:longint;
        end;
var
        n,i,tot,max:longint;
        st,mname:string;
        stu:array[1..100] of stud;
        flog:text;
        t1,t2:double;
procedure       setinput;
begin
        assign(input,'scholar.in');
        assign(output,'scholar.out');
        assign(flog,'scholar.log');
        append(flog);
        reset(input);
        rewrite(output);
        t1 := now;
end;
procedure       setoutput;
begin
        t2 := now;
        writeln(flog,(t2-t1)*24*3600:0:10);
        close(flog);
        close(input);
        close(output);
end;
function        done(st:string):stud;
var
        temp:stud;
        i,j:longint;
begin
        st := st+' ';
        i := 1;
        j := 1;
        while st[j] <> ' ' do  inc(j);
        temp.name := copy(st,i,j-i);
        inc(j);
        i := j;
        while st[j] <> ' ' do   inc(j);
        val(copy(st,i,j-i),temp.pj);
        inc(j);
        i := j;
        while st[j] <> ' ' do   inc(j);
        val(copy(st,i,j-i),temp.bj);
        inc(j);
        if st[j] = 'Y' then     temp.gb := true else    temp.gb := false;
        j := j+2;
        if st[j] = 'Y' then     temp.xb := true else    temp.xb := false;
        inc(j);
        inc(j);
        i := j;
        while st[j] <> ' ' do   inc(j);
        val(copy(st,i,j-i),temp.lw);
        temp.jj := 0;
        exit(temp);
end;
procedure       fj(var s:stud);
begin
        with s do
        begin
                if (pj > 80) and (lw >= 1) then jj := jj+8000;
                if (pj > 85) and (bj > 80) then jj := jj+4000;
                if (pj > 90)               then jj := jj+2000;
                if (pj > 85) and (xb)      then jj := jj+1000;
                if (bj > 80) and (gb)      then jj := jj+850 ;
        end;
end;
begin
        setinput;
        readln(n);
        for i := 1 to n do
        begin
                readln(st);
                stu[i] := done(st);
        end;
        for i := 1 to n do      fj(stu[i]);
        max := -maxlongint;
        tot := 0;
        for i := 1 to n do
        begin
                if stu[i].jj > max then
                begin
                        max := stu[i].jj;
                        mname := stu[i].name;
                end;
                tot := tot+stu[i].jj;
        end;
        writeln(mname);
        writeln(max);
        writeln(tot);
        setoutput;
end.

