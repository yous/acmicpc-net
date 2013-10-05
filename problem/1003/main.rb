gets.to_i.times{a=b=0;c=[gets.to_i];until (n=c.pop).nil?;n<1?a+=1:n<2?b+=1:c+=[n-1,n-2];end;puts "#{a} #{b}"}
