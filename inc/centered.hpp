#ifndef CENTERED_HPP
# define CENTERED_HPP

# include <string>
# include <iostream>
# include <iomanip>

template<typename charT>
class center_helper 
{
    std::basic_string<charT> str_;
public:
    center_helper(std::basic_string<charT> str) : str_(str) {}
    template <typename a>
    friend std::basic_ostream<a>& operator<<(std::basic_ostream<a>& s, const center_helper<a>& c);
};

center_helper<std::string::value_type> centered(const std::string& str);

template<typename charT>
std::basic_ostream<charT>& operator<<(std::basic_ostream<charT> &s, const center_helper<charT> &c)
{
    std::streamsize w = s.width();
    if (w > static_cast<long>(c.str_.length())) {
        std::streamsize left = (w + c.str_.length()) / 2;
        s.width(left);
        s << c.str_;
        s.width(w - left);
        s << "";
    } else {
        s << c.str_;
    }
    return s;
}

#endif
