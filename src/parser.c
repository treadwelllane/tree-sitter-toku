#include "tree_sitter/parser.h"

#if defined(__GNUC__) || defined(__clang__)
#pragma GCC diagnostic ignored "-Wmissing-field-initializers"
#endif

#define LANGUAGE_VERSION 14
#define STATE_COUNT 8
#define LARGE_STATE_COUNT 4
#define SYMBOL_COUNT 8
#define ALIAS_COUNT 0
#define TOKEN_COUNT 5
#define EXTERNAL_TOKEN_COUNT 0
#define FIELD_COUNT 0
#define MAX_ALIAS_SEQUENCE_LENGTH 3
#define PRODUCTION_ID_COUNT 1

enum ts_symbol_identifiers {
  sym_content = 1,
  sym_template_start = 2,
  sym_template_end = 3,
  sym_template_content = 4,
  sym_source_file = 5,
  sym_template = 6,
  aux_sym_source_file_repeat1 = 7,
};

static const char * const ts_symbol_names[] = {
  [ts_builtin_sym_end] = "end",
  [sym_content] = "content",
  [sym_template_start] = "template_start",
  [sym_template_end] = "template_end",
  [sym_template_content] = "template_content",
  [sym_source_file] = "source_file",
  [sym_template] = "template",
  [aux_sym_source_file_repeat1] = "source_file_repeat1",
};

static const TSSymbol ts_symbol_map[] = {
  [ts_builtin_sym_end] = ts_builtin_sym_end,
  [sym_content] = sym_content,
  [sym_template_start] = sym_template_start,
  [sym_template_end] = sym_template_end,
  [sym_template_content] = sym_template_content,
  [sym_source_file] = sym_source_file,
  [sym_template] = sym_template,
  [aux_sym_source_file_repeat1] = aux_sym_source_file_repeat1,
};

static const TSSymbolMetadata ts_symbol_metadata[] = {
  [ts_builtin_sym_end] = {
    .visible = false,
    .named = true,
  },
  [sym_content] = {
    .visible = true,
    .named = true,
  },
  [sym_template_start] = {
    .visible = true,
    .named = true,
  },
  [sym_template_end] = {
    .visible = true,
    .named = true,
  },
  [sym_template_content] = {
    .visible = true,
    .named = true,
  },
  [sym_source_file] = {
    .visible = true,
    .named = true,
  },
  [sym_template] = {
    .visible = true,
    .named = true,
  },
  [aux_sym_source_file_repeat1] = {
    .visible = false,
    .named = false,
  },
};

static const TSSymbol ts_alias_sequences[PRODUCTION_ID_COUNT][MAX_ALIAS_SEQUENCE_LENGTH] = {
  [0] = {0},
};

static const uint16_t ts_non_terminal_alias_map[] = {
  0,
};

static const TSStateId ts_primary_state_ids[STATE_COUNT] = {
  [0] = 0,
  [1] = 1,
  [2] = 2,
  [3] = 3,
  [4] = 4,
  [5] = 5,
  [6] = 6,
  [7] = 7,
};

static bool ts_lex(TSLexer *lexer, TSStateId state) {
  START_LEXER();
  eof = lexer->eof(lexer);
  switch (state) {
    case 0:
      if (eof) ADVANCE(6);
      if (lookahead == '%') ADVANCE(3);
      if (lookahead == '<') ADVANCE(1);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(0);
      END_STATE();
    case 1:
      if (lookahead == '%') ADVANCE(10);
      END_STATE();
    case 2:
      if (lookahead == '%') ADVANCE(10);
      if (lookahead != 0) ADVANCE(8);
      END_STATE();
    case 3:
      if (lookahead == '>') ADVANCE(11);
      END_STATE();
    case 4:
      if (lookahead != 0 &&
          lookahead != '%') ADVANCE(8);
      END_STATE();
    case 5:
      if (lookahead != 0 &&
          lookahead != '>') ADVANCE(13);
      END_STATE();
    case 6:
      ACCEPT_TOKEN(ts_builtin_sym_end);
      END_STATE();
    case 7:
      ACCEPT_TOKEN(sym_content);
      if (lookahead == '<') ADVANCE(2);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(7);
      if (lookahead != 0) ADVANCE(8);
      END_STATE();
    case 8:
      ACCEPT_TOKEN(sym_content);
      if (lookahead == '<') ADVANCE(4);
      if (lookahead != 0) ADVANCE(8);
      END_STATE();
    case 9:
      ACCEPT_TOKEN(sym_content);
      if (eof) ADVANCE(6);
      if (lookahead == '<') ADVANCE(2);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(7);
      if (lookahead != 0) ADVANCE(8);
      END_STATE();
    case 10:
      ACCEPT_TOKEN(sym_template_start);
      END_STATE();
    case 11:
      ACCEPT_TOKEN(sym_template_end);
      END_STATE();
    case 12:
      ACCEPT_TOKEN(sym_template_content);
      if (lookahead == '%') ADVANCE(5);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(12);
      if (lookahead != 0) ADVANCE(13);
      END_STATE();
    case 13:
      ACCEPT_TOKEN(sym_template_content);
      if (lookahead == '%') ADVANCE(5);
      if (lookahead != 0) ADVANCE(13);
      END_STATE();
    default:
      return false;
  }
}

static const TSLexMode ts_lex_modes[STATE_COUNT] = {
  [0] = {.lex_state = 0},
  [1] = {.lex_state = 9},
  [2] = {.lex_state = 9},
  [3] = {.lex_state = 9},
  [4] = {.lex_state = 9},
  [5] = {.lex_state = 12},
  [6] = {.lex_state = 0},
  [7] = {.lex_state = 0},
};

static const uint16_t ts_parse_table[LARGE_STATE_COUNT][SYMBOL_COUNT] = {
  [0] = {
    [ts_builtin_sym_end] = ACTIONS(1),
    [sym_template_start] = ACTIONS(1),
    [sym_template_end] = ACTIONS(1),
  },
  [1] = {
    [sym_source_file] = STATE(6),
    [sym_template] = STATE(2),
    [aux_sym_source_file_repeat1] = STATE(2),
    [ts_builtin_sym_end] = ACTIONS(3),
    [sym_content] = ACTIONS(5),
    [sym_template_start] = ACTIONS(7),
  },
  [2] = {
    [sym_template] = STATE(3),
    [aux_sym_source_file_repeat1] = STATE(3),
    [ts_builtin_sym_end] = ACTIONS(9),
    [sym_content] = ACTIONS(11),
    [sym_template_start] = ACTIONS(7),
  },
  [3] = {
    [sym_template] = STATE(3),
    [aux_sym_source_file_repeat1] = STATE(3),
    [ts_builtin_sym_end] = ACTIONS(13),
    [sym_content] = ACTIONS(15),
    [sym_template_start] = ACTIONS(18),
  },
};

static const uint16_t ts_small_parse_table[] = {
  [0] = 2,
    ACTIONS(23), 1,
      sym_template_start,
    ACTIONS(21), 2,
      ts_builtin_sym_end,
      sym_content,
  [8] = 1,
    ACTIONS(25), 1,
      sym_template_content,
  [12] = 1,
    ACTIONS(27), 1,
      ts_builtin_sym_end,
  [16] = 1,
    ACTIONS(29), 1,
      sym_template_end,
};

static const uint32_t ts_small_parse_table_map[] = {
  [SMALL_STATE(4)] = 0,
  [SMALL_STATE(5)] = 8,
  [SMALL_STATE(6)] = 12,
  [SMALL_STATE(7)] = 16,
};

static const TSParseActionEntry ts_parse_actions[] = {
  [0] = {.entry = {.count = 0, .reusable = false}},
  [1] = {.entry = {.count = 1, .reusable = false}}, RECOVER(),
  [3] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_source_file, 0, 0, 0),
  [5] = {.entry = {.count = 1, .reusable = true}}, SHIFT(2),
  [7] = {.entry = {.count = 1, .reusable = false}}, SHIFT(5),
  [9] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_source_file, 1, 0, 0),
  [11] = {.entry = {.count = 1, .reusable = true}}, SHIFT(3),
  [13] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0),
  [15] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0), SHIFT_REPEAT(3),
  [18] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0), SHIFT_REPEAT(5),
  [21] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_template, 3, 0, 0),
  [23] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_template, 3, 0, 0),
  [25] = {.entry = {.count = 1, .reusable = true}}, SHIFT(7),
  [27] = {.entry = {.count = 1, .reusable = true}},  ACCEPT_INPUT(),
  [29] = {.entry = {.count = 1, .reusable = true}}, SHIFT(4),
};

#ifdef __cplusplus
extern "C" {
#endif
#ifdef TREE_SITTER_HIDE_SYMBOLS
#define TS_PUBLIC
#elif defined(_WIN32)
#define TS_PUBLIC __declspec(dllexport)
#else
#define TS_PUBLIC __attribute__((visibility("default")))
#endif

TS_PUBLIC const TSLanguage *tree_sitter_toku(void) {
  static const TSLanguage language = {
    .version = LANGUAGE_VERSION,
    .symbol_count = SYMBOL_COUNT,
    .alias_count = ALIAS_COUNT,
    .token_count = TOKEN_COUNT,
    .external_token_count = EXTERNAL_TOKEN_COUNT,
    .state_count = STATE_COUNT,
    .large_state_count = LARGE_STATE_COUNT,
    .production_id_count = PRODUCTION_ID_COUNT,
    .field_count = FIELD_COUNT,
    .max_alias_sequence_length = MAX_ALIAS_SEQUENCE_LENGTH,
    .parse_table = &ts_parse_table[0][0],
    .small_parse_table = ts_small_parse_table,
    .small_parse_table_map = ts_small_parse_table_map,
    .parse_actions = ts_parse_actions,
    .symbol_names = ts_symbol_names,
    .symbol_metadata = ts_symbol_metadata,
    .public_symbol_map = ts_symbol_map,
    .alias_map = ts_non_terminal_alias_map,
    .alias_sequences = &ts_alias_sequences[0][0],
    .lex_modes = ts_lex_modes,
    .lex_fn = ts_lex,
    .primary_state_ids = ts_primary_state_ids,
  };
  return &language;
}
#ifdef __cplusplus
}
#endif
