class Bulk_quote : public Disc_quote {
public:
    using Disc_quote::Disc_quote;
    double net_price(size_t) const override;
    void debug() const override;
};