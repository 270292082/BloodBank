#ifndef DISPLAY_H
#define DISPLAY_H

enum pages {
  logo,
  intro,
  donor,
  donor_reg,
  login,
  recipient,
  recipient_reg,
  admin,
  booking
};

void display(pages page);

#endif
