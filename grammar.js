module.exports = grammar({
  name: "toku",
  rules: {
    source_file: $ => repeat(choice($.content, $.template)),
    content: $ => /([^<]|<[^%])*/,
    template: $ => seq($.template_start, $.template_content, $.template_end),
    template_start: $ => '<%',
    template_end: $ => '%>',
    template_content: $ => /([^%]|%[^>])*/
  }
});
