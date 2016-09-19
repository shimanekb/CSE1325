#ifndef _PUBLICATION_H 
#define _PUBLICATION_H 2016

#include <string>
#include "customer.h"

class Publication { public:
        enum Genre {
            FICTION,
            NON_FICTION,
            SELF_HELP,
            PERFORMANCE
        };
        enum TargetAge {
            CHILDREN,
            TEEN,
            ADULT,
            RESTRICTED 
        };
        enum MediaType {
            BOOK,
            PERIODICAL,
            NEWSPAPER,
            AUDIO,
            VIDEO
        };
        Publication(std::string isbn, std::string title, std::string author, int copyright_year
                , Publication::Genre genre, Publication::TargetAge target_age,
                Publication::MediaType media_type);
        Publication(std::string isbn, std::string title, std::string author, int copyright_year
                , Publication::Genre genre, Publication::TargetAge target_age,
                Publication::MediaType media_type, bool is_checkedout);
        Publication(std::string isbn, std::string title, std::string author, int copyright_year
                , Publication::Genre genre, Publication::TargetAge target_age,
                Publication::MediaType media_type, bool is_checkedout, 
                std::string customer_name, std::string customer_phone);
        std::string get_isbn();
        std::string get_title();
        std::string get_author();
        Genre get_genre();
        int get_copyright_year();
        TargetAge get_target_age();
        MediaType get_media_type();
        bool is_checked_out();
        void set_checkout(bool status);
        void set_customer_name(std::string name);
        void set_customer_phone(std::string phone);
        std::string get_customer_name();
        std::string get_customer_phone();
        std::string ToString();
    private:
        const std::string kIsbn;
        const std::string kTitle;
        const std::string kAuthor;
        const int kCopyrightYear;
        const Publication::Genre kGenre;
        const Publication::TargetAge kTargetAge;
        const Publication::MediaType kMediaType;
        bool is_checkedout;
        std::string customer_name;
        std::string customer_phone;
        std::string GetGenreString();
        std::string GetTargetAgeString();
        std::string GetMediaTypeString();
};

#endif
