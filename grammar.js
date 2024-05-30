module.exports = grammar({
  name: "toku",
  rules: {
    source_file: $ => repeat(choice($.content, $.template)),
    content: $ => /([^<]|<[^%])*/,
    template: $ => seq('<%', $.template_content, '%>'),
    template_content: $ => /([^%]|%[^>])*/
  }
});
