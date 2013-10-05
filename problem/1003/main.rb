gets.to_i.times{a=Hash.new(0);a[n=gets.to_i]=1;n.downto(2){|i|c=a[i];a[i-1]+=c;a[i-2]+=c};puts "#{a[0]} #{a[1]}"}
