#include "hashing.hpp"

#include <fmt/format.h>
#include <jinja2cpp/template.h>
#include <sstream>
#include <fstream>
#include <httplib.h>
#include <filesystem>



std::string get_html_template(std::filesystem::path const & target_file){
    if(std::filesystem::exists(target_file)){
        std::stringstream ss;
        std::ifstream file_stream(target_file);
        ss << file_stream.rdbuf();
        return ss.str();
    }
    return {};
}

std::string dynamic_title(){
    return "a dynamic title";
}

std::string dynamic_body(){
    return "a dynamic body(\n this body was created in a function. \n This is dnyamic gernation.";
}

int main() {

    std::cout << "asdfsadfsadf:" << wst::sha256("fox") << '\n';
    // the routing server.
    httplib::Server svr;

    // Routing the index address
    svr.Get("/", [](const httplib::Request &, httplib::Response &res) {
        jinja2::Template jinja;

        jinja.Load(get_html_template(std::filesystem::current_path()/"html"/"body_template.html"));

        res.set_content(jinja.RenderAsString({{"my_title", dynamic_title()},
                                              {"my_body",  dynamic_body()}}).value(), "text/html");
    });

    svr.listen("0.0.0.0", 8080);
}
