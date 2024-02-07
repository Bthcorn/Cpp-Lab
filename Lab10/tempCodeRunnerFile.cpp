 // auto it = std::unique(result.exps.begin(), result.exps.end(), [](const Term &a, const Term &b) {
        //     return a.exp == b.exp;
        // });
        // it = std::remove_if(result.exps.begin(), result.exps.end(), [](const Term &a) {
        //     return a.coeff == 0;
        // });
        // result.exps.resize(std::distance(result.exps.begin(), it));