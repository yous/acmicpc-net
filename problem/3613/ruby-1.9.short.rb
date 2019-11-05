# encoding: utf-8
s=gets;puts s[/^[a-z][A-Za-z]*$/]?s.gsub(/([A-Z])/,"_\\1").downcase: s[/^[a-z](_?[a-z])*$/]?s.gsub(/_([a-z])/){$1.upcase}:"Error!"

# name = gets.chomp
# puts case name
#      when /^[a-z][A-Za-z]*$/
#        name.gsub(/([A-Z])/, "_\\1").downcase
#      when /^[a-z](?:_?[a-z])*$/
#        name.gsub(/_([a-z])/) { Regexp.last_match[1].upcase }
#      else
#        "Error!"
#      end
