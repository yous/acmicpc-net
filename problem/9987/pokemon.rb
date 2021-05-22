require 'mechanize'

a = Mechanize.new
page = a.get('http://web.archive.org/web/20140301191716/http://pokemondb.net/pokedex/national')

File.open('pokemon.cpp', 'w') do |f|
  f.write("vector<pair<string, string>> pokemon = {\n")
  f.write("    { \"\", \"\" },\n")

  page.search('span.infocard-tall').each do |pokemon|
    f.write("    { \"#{pokemon.search('a.ent-name').text}\", \"#{pokemon.search('small.aside>a').map(&:text).join(' ')}\" },\n")
  end
  f.write("};\n")
end
